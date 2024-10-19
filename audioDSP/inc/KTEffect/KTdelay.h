#ifndef KTDELAY_H
#define KTDELAY_H

#include "softClip.h"
#include "KTaudio.h"



class KT_delay {

    public:

    KT_ERROR KT_Delay_init();
    KT_ERROR KT_Delay_set();
    KT_ERROR KT_Delay_get();
    KT_ERROR KT_Delay_process();

    private:
    SoftClip softClip;
};

#endif //KTDELAY_H
