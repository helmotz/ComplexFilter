#ifndef _WAVEFORM_GENERATOR_H_
#define _WAVEFORM_GENERATOR_H_

#include <cmath>
#include <memory>

template <typename T, int N> class WaveformGenerator
{
  private:
    std::unique_ptr<T[]> _samples;
    T _amplitude;
    T *_samplesPtr;
    int _counter;
  public:
    WaveformGenerator(float fc, float frequency, T amplitude):_samples(new T[N]), _amplitude(amplitude), _counter(0)
    {
    	_samplesPtr = _samples.get();
    	for (int i=0; i<N; ++i)
    	   _samplesPtr[i] = (T) amplitude*cos(2.0*M_PI*i*frequency/fc);
    }
    
    void reset()
    {
      _counter=0;
    }
    
    T getSample()
    {
      T sample=_samplesPtr[_counter++];
      _counter = _counter % N;

      return sample;
    }
};

#endif