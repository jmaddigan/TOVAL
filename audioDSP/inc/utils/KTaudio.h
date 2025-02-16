#ifndef KTAUDIO_H
#define KTAUDIO_H

//Use ifdef to stop definition of enum twice if called mulitiple times

#include <cstdint>

#define KT_VERSION_MAJOR 1
#define KT_VERSION_MINOR 0
#define KT_VERSION_PATCH 0

#define NUM_SAMPLES_PER_CHANNEL 1024
#define NUM_CHANNELS 2
#define SAMPLE_RATE 48000
#define BIQUAD_NUM_COEFFS 5

enum class KT_ERROR : std::uint32_t{
    NO_ERROR = 0,
    SIZE_ERROR = 1,
    PARAMID_ERROR = 2,
    PARAMETER_ERROR = 3,
    NULL_PTR_ERROR = 4
    // Make full list of error codes
};

/*
enum class ModuleChannels {
    GAIN = 2, // e.g., 2 channels
    SOFTCLIP = 1, // e.g., 1 channel
    EQ = 2, // e.g., 2 channels
    ModuleD = 4, // e.g., 4 channels
    ModuleE = 1  // e.g., 1 channel
};
*/


// If need to add more global variables, make enum public part of bigger class

#endif