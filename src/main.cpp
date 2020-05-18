#include <Arduino.h>
#include <memory>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include "driver/periph_ctrl.h"
#include <driver/timer.h>
#include <driver/adc.h>
#include <driver/dac.h>

#include "ComplexFilter.h"

#define TIMER_DIVIDER         8
#define TIMER_SCALE           (TIMER_BASE_CLK / TIMER_DIVIDER)


static void IRAM_ATTR timer0_isr(void *p)
{
  ComplexFilter *flt = (ComplexFilter *)p;

  ComplexFilter::ResultType i_res = flt->getI();
  ComplexFilter::ResultType q_res = flt->getQ();


  dac_output_voltage(DAC_CHANNEL_1, i_res >> 24);
  dac_output_voltage(DAC_CHANNEL_2, q_res >> 24);

#ifndef _DEBUG_
  ComplexFilter::SampleType sample=adc1_get_raw(ADC1_CHANNEL_0);
#else
  static ComplexFilter::SampleType sample=0;
  sample++;
#endif

  flt->enqueueSample(sample, true);

  TIMERG0.int_clr_timers.t0 = 1;

  timer_set_alarm(TIMER_GROUP_0, TIMER_0, TIMER_ALARM_EN);
  timer_enable_intr(TIMER_GROUP_0, TIMER_0);
  timer_start(TIMER_GROUP_0, TIMER_0);
}


static void timer0_setup(ComplexFilter *filter,  double timer_interval_sec)
{
    /* Select and initialize basic parameters of the timer */
    timer_config_t config; // default clock source is APB
 
    config.divider = TIMER_DIVIDER;
    config.counter_dir = TIMER_COUNT_DOWN;
    config.counter_en = TIMER_PAUSE;
    config.intr_type = TIMER_INTR_LEVEL;
    config.auto_reload = true;

    timer_init(TIMER_GROUP_0, TIMER_0, &config);
    timer_set_counter_value(TIMER_GROUP_0, TIMER_0, timer_interval_sec * TIMER_SCALE);
    timer_set_alarm_value(TIMER_GROUP_0, TIMER_0, 0);
    timer_set_alarm(TIMER_GROUP_0, TIMER_0, TIMER_ALARM_EN);
    timer_isr_register(TIMER_GROUP_0, TIMER_0, &timer0_isr, (void *) filter, ESP_INTR_FLAG_IRAM, NULL);
    timer_enable_intr(TIMER_GROUP_0, TIMER_0);
    timer_start(TIMER_GROUP_0, TIMER_0);
}

extern ComplexFilter::TapType taps_i[512];
extern ComplexFilter::TapType taps_q[512];

ComplexFilter filter(512, taps_i, taps_q);

void setup() {
  Serial.begin(115200);
  vTaskDelay(1000 / portTICK_PERIOD_MS);

#ifndef _DEBUG_
  timer0_setup(&filter, 0.0001);
#else  
  timer0_setup(&filter, 1.0);
#endif

  adc1_config_width(ADC_WIDTH_BIT_12);
  adc1_config_channel_atten(ADC1_CHANNEL_0,ADC_ATTEN_DB_0);

  dac_output_enable(DAC_CHANNEL_1);
  dac_output_enable(DAC_CHANNEL_2);

  xTaskCreate((TaskFunction_t)ComplexFilter::staticMainLoop, "mainLoop", 2048, &filter, 5, NULL);
}

void loop() {
}