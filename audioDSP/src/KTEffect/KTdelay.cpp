#include <iostream>
#include "KTdelay.h"
#include "KTaudio.h"
using namespace std;

KT_ERROR KT_delay::KT_Delay_init(){

  KT_ERROR ret = KT_ERROR::KT_NO_ERROR;
  cout<<"Calling first module in KT init"<<endl;
  ret = softClip.softClip_init();
  return ret;
}

KT_ERROR KT_delay::KT_Delay_set(){
  KT_ERROR ret = KT_ERROR::KT_NO_ERROR;
  cout<<"Calling first module in KT set"<<endl;
  ret = softClip.softClip_set();
  return ret;
}

KT_ERROR KT_delay::KT_Delay_get(){
  KT_ERROR ret = KT_ERROR::KT_NO_ERROR;
  cout<<"Calling first module in KT get"<<endl;
  ret = softClip.softClip_get();
  return ret;
}

KT_ERROR KT_delay::KT_Delay_process(){
  KT_ERROR ret = KT_ERROR::KT_NO_ERROR;
  cout<<"Calling first module in KT process"<<endl;
  ret = softClip.softClip_process();
  return ret;
}