#ifndef KT_ADAPTIVEEQ_P_H
#define KT_ADAPTIVEEQ_P_H

#include "EQ.h"
#include "KT_AdaptiveEQ.h"  // Include the public header

// Define the struct that holds the private implementation
struct KT_AdaptiveEQ::Impl {
    // Private member variables
    EQ pEQ;

    // Private methods
    KT_ERROR internalProcess();
    KT_ERROR KT_do_AdaptiveEQ_set();
    KT_ERROR KT_AdaptiveEQ_do_set(uint32_t moduleID, uint16_t paramID, uint16_t data_length, void* data);

    enum Modules
    {
        EQ
        // More Modules to be included
    };
};

struct KT_AdaptiveEQ::Variables {
    // Private member variables
    uint32_t repeat_counter;
};

#endif // KT_ADAPTIVEEQ_P_H