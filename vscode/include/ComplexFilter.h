#ifndef _COMPLEX_FILTER_H_
#define _COMPLEX_FILTER_H_

#include <memory>
#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>


class ComplexFilter
{
  public:
    using TapType = int32_t;
    using SampleType = int32_t;
    using ResultType = int32_t;

  private:
    struct SampleEvent
    {
      SampleType sample;
    };

    int _ntaps;
    std::unique_ptr<TapType []>    _iTaps;
    std::unique_ptr<TapType []>    _qTaps;
    std::unique_ptr<SampleType []> _samples;

    TapType * _iTapsPtr;
    TapType * _qTapsPtr;

    SampleType * _samplesPtr;

    int _samplePos;

    ResultType _I;
    ResultType _Q;

    xQueueHandle _sampleQueue;

    void addSample(SampleType sample);
    void calculateOutput(ResultType &i_res, ResultType &q_res);
    void setResult(ResultType i_res, ResultType q_res);

    ResultType scalar_product(TapType *t, SampleType *s);

  public:
    ComplexFilter();
    ComplexFilter(int ntaps, TapType *i_taps, TapType *q_taps);
    ComplexFilter(const ComplexFilter &) = delete;

    ComplexFilter & operator = (const ComplexFilter &) = delete;

    void setTaps(int n_taps, TapType *i_taps, TapType *q_taps);

    ResultType getI() const;
    ResultType getQ() const;

    void enqueueSample(SampleType sample, bool from_isr);
    static void staticMainLoop(ComplexFilter *instance);
    void mainLoop();
};

#endif