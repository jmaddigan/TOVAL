#ifndef EQ_H
#define EQ_H

#include <cstddef>
#include <cstdint>
#include <math.h>

#include "KTaudio.h"
#include "adaptive_Biquad.h"
#include "conversionFN.h"


class EQ {

    public:
 
    KT_ERROR EQ_init();
    KT_ERROR EQ_set(uint16_t ParamID, size_t data_length, void* data);
    KT_ERROR EQ_get(uint16_t ParamID, size_t data_length, void* data);
    KT_ERROR EQ_process(float **ppIn, float **ppOut);

    /*
        Don't need the module ID for inside here. For loop itterating through each module ID is done in Delay effect do_set,
        therefor if module ID is soft clip, EQ_do_set just needs to itterate through param ID's

        Look into whether I need to include set to do_set function call.
    */


    private:

    KT_ERROR set_minGain(size_t data_length, void* data);                   // Done
    KT_ERROR set_maxGain(size_t data_length, void* data);                   // Done
    KT_ERROR set_stepResponse(size_t data_length, void* data);              // Done
    KT_ERROR interpolateCurrentGain(float *ppIn);       // Done
    


    KT_ERROR set_MinMaxBiquadCoeff(size_t data_length, void* data);               // Done

    KT_ERROR EQ_do_set(uint16_t ParamID, size_t data_length, void* data);
    KT_ERROR set_enable(size_t data_length, void* data);
    //KT_ERROR set_biquad_data(size_t data_length, void* data);
    KT_ERROR set_distortion(uint32_t ModuleID, uint32_t ParamID, size_t data_length, void* data);

    KT_ERROR EQ_do_get(uint16_t ParamID, size_t data_length, void* data);
    KT_ERROR get_enable(size_t data_length, void* data);
    KT_ERROR get_biquad_data(size_t data_length, void* data);
    KT_ERROR get_distortion(size_t data_length, void* data);

    uint32_t enable;       // Check where ref code stores enable variable, and how it passes data
    float In;
    float Out;

    float maxGain;
    float minGain;
    float stepResponseAlpha;
    float stepResponseMin = 0.3;
    float stepResponseMax = 0.9;
    float currentScale;

    struct filterFeatures
    {
        float freq;
        float gain_dB;
        float Q;
        int minORmax;
    };
    
    enum Filter
    {
        MIN_FILTER,
        MAX_FILTER
    };

    enum EQChannels
    {
        LEFT,
        RIGHT
    };


    struct EQbiquadcoeff
    {
        uint32_t channelID;
        float coeff[BIQUAD_NUM_COEFFS];
    };

    EQbiquadcoeff minBiquadCoeffs;
    EQbiquadcoeff maxBiquadCoeffs;

    AdaptiveBiquad adaptiveBiquad_L;
    AdaptiveBiquad adaptiveBiquad_R;

    uint16_t num_channels = NUM_CHANNELS;

    enum Params
    {
        ENABLE,
        MIN_GAIN,
        MAX_GAIN,
        STEP_RESPONSE,
        BIQUAD_COEFFS
    };
};

// Look into using 16 bit integers for arguments. also using template instead of void* for data


#endif //MODULE1_H
