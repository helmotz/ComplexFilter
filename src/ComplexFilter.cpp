#include "ComplexFilter.h"

void ComplexFilter::addSample(ComplexFilter::SampleType sample)
{
    _samplePos--;
    if (_samplePos < 0)
        _samplePos = _ntaps-1;

    _samplesPtr[_samplePos] = sample;
    _samplesPtr[_samplePos+_ntaps] = sample;
}

void ComplexFilter::calculateOutput(ComplexFilter::ResultType & i_res, ComplexFilter::ResultType & q_res)
{
    i_res = scalar_product(_iTapsPtr, &_samplesPtr[_samplePos]);
    q_res = scalar_product(_qTapsPtr, &_samplesPtr[_samplePos]);
}

ComplexFilter::ResultType ComplexFilter::scalar_product(ComplexFilter::TapType *t, ComplexFilter::SampleType *s)
{
    ResultType res=0;
    for (int i=0; i < _ntaps; ++i)
    {
        res += t[i]*s[i];
    }

    return res;
}

ComplexFilter::ComplexFilter():
    _ntaps(0), 
    _iTaps(nullptr),
    _qTaps(nullptr), 
    _samples(nullptr),
    _iTapsPtr(nullptr),
    _qTapsPtr(nullptr),
    _samplesPtr(nullptr),
    _samplePos(1),
    _I(0),
    _Q(0)
{
    _sampleQueue = xQueueCreate(10, sizeof(SampleEvent));
}

void ComplexFilter::setTaps(int ntaps, ComplexFilter::TapType *i_taps, ComplexFilter::TapType *q_taps)
{
    _ntaps = ntaps;
    _iTaps = std::unique_ptr<TapType[] >(new TapType[ntaps]);
    _qTaps = std::unique_ptr<TapType[] >(new TapType[ntaps]);
    _samples = std::unique_ptr<SampleType[] >(new SampleType[2*ntaps]);

    _iTapsPtr    = _iTaps.get();
    _qTapsPtr    = _qTaps.get();

    _samplesPtr = _samples.get();

    for (int i=0; i<ntaps; ++i)
        _iTaps[i] = i_taps[i];

    for (int i=0; i<ntaps; ++i)
        _qTaps[i] = q_taps[i];

    for (int i=0; i<2*ntaps; ++i)
        _samples[i] = 0;
}


void ComplexFilter::setResult(ComplexFilter::ResultType i_res, ComplexFilter::ResultType q_res)
{
    _I = i_res;
    _Q = q_res;

#ifdef _DEBUG_
    Serial.print("I: ");
    Serial.println(_I, DEC);
    Serial.print("Q: ");
    Serial.println(_Q, DEC);
#endif
}

ComplexFilter::ResultType ComplexFilter::getI() const
{
    return _I;
}

ComplexFilter::ResultType ComplexFilter::getQ() const
{
    return _Q;
}

void ComplexFilter::enqueueSample(ComplexFilter::SampleType sample, bool from_isr)
{
    SampleEvent event;

    event.sample = sample;

    if (from_isr)
        xQueueSendFromISR(_sampleQueue, &event, NULL);
    else
        xQueueSend(_sampleQueue, &event, portMAX_DELAY);   
}


void ComplexFilter::mainLoop(ComplexFilter *instance)
{
    ResultType i_res, q_res;

    while (true)
    {
        SampleEvent event;
        if (xQueueReceive(instance->_sampleQueue, &event, portMAX_DELAY) == pdTRUE)
        {
#ifdef _DEBUG_
            Serial.println(event.sample);
#endif
            instance->addSample(event.sample);
            instance->calculateOutput(i_res, q_res);
            instance->setResult(i_res, q_res);
        }
    }
}