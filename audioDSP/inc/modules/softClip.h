#ifndef SOFTCLIP_H
#define SOFTCLIP_H
#include "KTaudio.h"


class SoftClip {

    public:
 
    KT_ERROR softClip_init();
    KT_ERROR softClip_set();
    KT_ERROR softClip_get();
    KT_ERROR softClip_process();

    private:
};


#endif //MODULE1_H
