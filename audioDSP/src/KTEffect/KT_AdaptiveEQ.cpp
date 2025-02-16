#include "KT_AdaptiveEQ.h"
#include "KT_AdaptiveEQ_p.h"
#include <iostream>

using namespace std;

KT_AdaptiveEQ::KT_AdaptiveEQ() : pImpl(new Impl) {}   // constructor is called when new object of class KT_delay is called. This then initialises a new object of the internal struct 'Impl' named pImpl

KT_AdaptiveEQ::~KT_AdaptiveEQ() {
    delete pImpl;
}

KT_ERROR KT_AdaptiveEQ::KT_AdaptiveEQ_init()
{
  KT_ERROR ret = KT_ERROR::NO_ERROR;
  cout<<"Calling first module in KT init"<<endl;
  ret = pImpl->pEQ.EQ_init();
  return ret;
  
}

KT_ERROR KT_AdaptiveEQ::KT_AdaptiveEQ_set(uint16_t moduleID, uint16_t paramID, uint16_t datalength, void* data)
{
  KT_ERROR ret = KT_ERROR::NO_ERROR;
  cout<<"Calling first module in KT set"<<endl;

  /*
    Potential preset idea. Where the instance of pImpl is defined, you could have several Impl objects, one for each preset.
    This way you can pass Preset ID as an argument to the public functions, and then a switch case where you then call the do set,
    but it will be setting the private structure variables for that specific preset impl.

    Only try this addition of preset IDs to the public functions once library is working on 1 instance.
  */


  ret = pImpl->KT_AdaptiveEQ_do_set(moduleID, paramID, datalength, data);
  //call the specific instance of the Internal Impl struct and its sub function.
  return ret;  
}

KT_ERROR KT_AdaptiveEQ::Impl::KT_AdaptiveEQ_do_set(uint32_t moduleID, uint16_t paramID, uint16_t data_length, void* data)
{

  KT_ERROR ret = KT_ERROR::NO_ERROR;

  switch(moduleID)
  {
    case EQ:
    {
      ret = pEQ.EQ_set(paramID, data_length, (void*) data);
    }
    default:
    {
      cout << "Error: No Parameter recognised" << endl;
      ret = KT_ERROR::PARAMID_ERROR;
    }
  }
}

KT_ERROR KT_AdaptiveEQ::KT_AdaptiveEQ_get()
{
  KT_ERROR ret = KT_ERROR::NO_ERROR;
  cout<<"Calling first module in KT get"<<endl;
  //ret = pImpl->softClip.softClip_get();
  return ret;
}

KT_ERROR KT_AdaptiveEQ::KT_AdaptiveEQ_process(float **ppIn, float **ppOut)
{
  KT_ERROR ret = KT_ERROR::NO_ERROR;
  cout<<"Calling first module in KT process"<<endl;

  
  ret = pImpl->pEQ.EQ_process(ppIn, ppOut);


  if (pVariables->repeat_counter == 0)
  {
    
  }

  return ret;
}

KT_ERROR KT_AdaptiveEQ::Impl::internalProcess()
{

  KT_ERROR ret = KT_ERROR::NO_ERROR;
  cout<<"Calling first module in KT init"<<endl;
  ret = pEQ.EQ_init();    // Only init because havent passed input yet
    // Private processing logic
  return ret;
}
