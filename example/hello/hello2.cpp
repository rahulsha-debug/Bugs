
// 
#include <systemc>

SC_MODULE(hello)
{
  
  SC_CTOR(hello)
  {
    SC_METHOD(DisplayMth);
    sensitive << trigger;
    dont_initialize();
    SC_METHOD(TriggerMth);
  }

  void DisplayMth()
  {
    std::cout << "@@" << sc_core::sc_time_stamp() << " " << name() << " => hello world" << std::endl;
  }

  void TriggerMth()
  {
    trigger.notify(5, sc_core::SC_NS);
    trigger.notify(4, sc_core::SC_NS);
    trigger.notify(2, sc_core::SC_NS);
    trigger.notify();
  }
  sc_core::sc_event trigger;
};


int sc_main(int argc, char** argv)
{
  hello greet("greet");

  sc_core::sc_start();
  // sc_core::sc_stop();
  return 0;
}
