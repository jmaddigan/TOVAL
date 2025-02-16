#include <iostream>
#include "EQ.h"
using namespace std;

KT_ERROR EQ::EQ_init()
{
  KT_ERROR ret = KT_ERROR::NO_ERROR;
  cout<<"EQ Init print"<<endl;

  ret = adaptiveBiquad_L.AdaptiveBiquad_init(EQChannels::LEFT);
  ret = adaptiveBiquad_R.AdaptiveBiquad_init(EQChannels::RIGHT);

  return ret;
}

KT_ERROR EQ::EQ_set(uint16_t ParamID, size_t data_length, void* data)
{
  KT_ERROR error = KT_ERROR::NO_ERROR;
  cout<<"EQ Set print"<<endl;

  error = EQ_do_set(ParamID, data_length, data);

  return error;
}

KT_ERROR EQ::EQ_do_set(uint16_t ParamID, size_t data_length, void* data)
{
  KT_ERROR ret = KT_ERROR::NO_ERROR;

  switch(ParamID)
  {
    case ENABLE:
    {
      ret = set_enable(data_length, data);
    }
    case MIN_GAIN:
    {
      ret = set_minGain(data_length, data);
    }
    case MAX_GAIN:
    {
      ret = set_maxGain(data_length, data);
    }
    case STEP_RESPONSE:
    {
      ret = set_stepResponse(data_length, data);
    }
    case BIQUAD_COEFFS:
    {
      ret = set_MinMaxBiquadCoeff(data_length, data);
    }
    // Need to do all...
    default:
    {
      cout << "Error: No Parameter recognised" << endl;
      ret = KT_ERROR::PARAMID_ERROR;
    }
  }
}

KT_ERROR EQ::set_enable(size_t data_length, void* data)
{
  cout<<"EQ set enable"<<endl;
  KT_ERROR ret = KT_ERROR::NO_ERROR;
  if(data_length == sizeof(enable))
  {
    enable = *reinterpret_cast<uint32_t*>(data); // Document reinterperet_cast vs static cast
  }
  else
  {
     ret = KT_ERROR::SIZE_ERROR;
  }
  return ret;
}

KT_ERROR EQ::get_enable(size_t data_length, void* data)
{
  cout<<"EQ get enable"<<endl;
  KT_ERROR ret = KT_ERROR::NO_ERROR;
  if(data_length == sizeof(enable))
  {
    *reinterpret_cast<uint32_t*>(data) = enable;
  }
  else
  {
    ret = KT_ERROR::SIZE_ERROR;
  }
}

KT_ERROR EQ::set_minGain(size_t data_length, void* data)
{
    KT_ERROR ret = KT_ERROR::NO_ERROR;

    ret = adaptiveBiquad_L.set_minGain(data_length, data);
    ret = adaptiveBiquad_R.set_minGain(data_length, data);

    return ret;
}

KT_ERROR EQ::set_maxGain(size_t data_length, void* data)
{
    KT_ERROR ret = KT_ERROR::NO_ERROR;

    // Currently setting same gain values, but can change this to be channel independent
    
    ret = adaptiveBiquad_L.set_maxGain(data_length, data);
    ret = adaptiveBiquad_R.set_maxGain(data_length, data);
    return ret;
}

KT_ERROR EQ::set_stepResponse(size_t data_length, void* data)
{
    KT_ERROR ret = KT_ERROR::NO_ERROR;
    
    ret = adaptiveBiquad_L.set_stepResponse(data_length, data);
    ret = adaptiveBiquad_R.set_stepResponse(data_length, data);

    return ret;
}


KT_ERROR EQ::set_MinMaxBiquadCoeff(size_t data_length, void* data)    // Needs to be called for L an R
{
    cout<<"Adaptive Biquad set min biquad Data"<<endl;
    KT_ERROR ret = KT_ERROR::NO_ERROR;

    filterFeatures features;

    if(data_length == sizeof(filterFeatures))
    {
        features = *reinterpret_cast<filterFeatures*>(data);
    }
    else
    {
        ret = KT_ERROR::SIZE_ERROR;
        cout << " Error in data size for set alpha" << endl;    // need to impliment print TAGS
    }

    float LinearGain = dbToLinear(features.gain_dB);

    // Calculate normalized frequency
    float w0 = (2 * M_PI * features.freq) / SAMPLE_RATE;
    float alpha = sin(w0) / (2 * features.Q);

    // Compute coefficients for Low-Pass Filter
    switch (features.minORmax)
    {
    case MIN_FILTER:
        {
            float cos_w0 = cos(w0);
            float a0 = 1 + alpha / LinearGain;

            minBiquadCoeffs.coeff[0] = (1 - cos_w0) / 2;            // b0
            minBiquadCoeffs.coeff[1] = 1 - cos_w0;                  // b1
            minBiquadCoeffs.coeff[2] = (1 - cos_w0) / 2;            // b2
            minBiquadCoeffs.coeff[3] = -2 * cos_w0;                 // a1
            minBiquadCoeffs.coeff[4] = 1 - alpha / LinearGain;      // a2

            // Normailise coefficients
            minBiquadCoeffs.coeff[0] /= a0;
            minBiquadCoeffs.coeff[1] /= a0;
            minBiquadCoeffs.coeff[2] /= a0;
            minBiquadCoeffs.coeff[3] /= a0;
            minBiquadCoeffs.coeff[4] /= a0;

            ret = adaptiveBiquad_L.set_minBiquadCoeff(sizeof(minBiquadCoeffs.coeff), minBiquadCoeffs.coeff);
            ret = adaptiveBiquad_R.set_minBiquadCoeff(sizeof(minBiquadCoeffs.coeff), minBiquadCoeffs.coeff);
        }
        break;
    case MAX_FILTER:
        {
            float cos_w0 = cos(w0);
            float a0 = 1 + alpha / LinearGain;

            maxBiquadCoeffs.coeff[0] = (1 - cos_w0) / 2;            // b0
            maxBiquadCoeffs.coeff[1] = 1 - cos_w0;                  // b1
            maxBiquadCoeffs.coeff[2] = (1 - cos_w0) / 2;            // b2
            maxBiquadCoeffs.coeff[3] = -2 * cos_w0;                 // a1
            maxBiquadCoeffs.coeff[4] = 1 - alpha / LinearGain;      // a2

            // Normailise coefficients
            maxBiquadCoeffs.coeff[0] /= a0;
            maxBiquadCoeffs.coeff[1] /= a0;
            maxBiquadCoeffs.coeff[2] /= a0;
            maxBiquadCoeffs.coeff[3] /= a0;
            maxBiquadCoeffs.coeff[4] /= a0;
            ret = adaptiveBiquad_L.set_maxBiquadCoeff(sizeof(maxBiquadCoeffs.coeff), maxBiquadCoeffs.coeff);
            ret = adaptiveBiquad_R.set_maxBiquadCoeff(sizeof(maxBiquadCoeffs.coeff), maxBiquadCoeffs.coeff);
        }
        break;
    
    default:
        {
            cout<<"ERROR. Min or Max filter number not recognised. Biquad set failed"<<endl;
            ret = KT_ERROR::PARAMETER_ERROR;
        }
        break;
    }

    if(ret == KT_ERROR::NO_ERROR)
    {
      // Add if statement for each Channel, currently the channel stays at 0 and passes the same coeffs to both L and R.
      // But in future the channel ID is passsed, so can set min and max biquads for each channel
      // Then if statement to call adaptiveBiquad_L or R depending on Channel ID and set biquad data seperatly

        
    }
    
    return ret;
}


KT_ERROR EQ::EQ_process(float **ppIn, float **ppOut) {
    KT_ERROR error = KT_ERROR::NO_ERROR;

    if(ppIn == nullptr || ppOut == nullptr)
    {
        cout << "Error: NULL pointer passed to EQ_process" << endl;
        return KT_ERROR::NULL_PTR_ERROR;
    }

    adaptiveBiquad_L.AdaptiveBiquad_process(ppIn[0],ppOut[0]);
    adaptiveBiquad_R.AdaptiveBiquad_process(ppIn[1],ppOut[1]);

    std::cout << "EQ Process print" << std::endl;
    return error;
}