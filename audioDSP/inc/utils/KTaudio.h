#ifndef KTAUDIO_H
#define KTAUDIO_H

//Use ifdef to stop definition of enum twice if called mulitiple times

#include <cstdint>

#define KT_VERSION_MAJOR 1
#define KT_VERSION_MINOR 0
#define KT_VERSION_PATCH 0

enum class KT_ERROR : std::uint32_t{
    KT_NO_ERROR = 0,
    KT_SIZE_ERROR = 1
    // Make full list of error codes
};

// If need to add more global variables, make enum public part of bigger class

#endif