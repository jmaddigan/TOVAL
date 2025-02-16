#ifndef KT_ADAPTIVEEQ_H
#define KT_ADAPTIVEEQ_H

#include "KTaudio.h"

class KT_AdaptiveEQ {
public:
    KT_AdaptiveEQ();
    ~KT_AdaptiveEQ();

    // Public methods
    KT_ERROR KT_AdaptiveEQ_init();
    KT_ERROR KT_AdaptiveEQ_set(uint16_t moduleID, uint16_t paramID, uint16_t datalength, void* data);
    KT_ERROR KT_AdaptiveEQ_get();
    KT_ERROR KT_AdaptiveEQ_process(float **ppIn, float **ppOut);

private:
    struct Impl;
    Impl* pImpl;  // Pointer to the private implementation
    
    struct Variables;
    Variables* pVariables;
    //Test
};

#endif // KT_ADAPTIVEEQ_H
