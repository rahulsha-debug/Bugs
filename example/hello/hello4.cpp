
// 
#include <systemc>

SC_MODULE(hello)
{
  
  SC_CTOR(hello)
  {
    SC_METHOD(DisplayMth);
    sensitive << trigger;
    dont_initialize();
    SC_THREAD(TriggerThr);
  }

  void DisplayMth()
  {
    std::cout << "@@" << sc_core::sc_time_stamp() << " " << name() << " => hello world" << std::endl;
  }

  void display(int number)
  {
    wait(5, sc_core::SC_NS);
    std::cout << "@@" << sc_core::sc_time_stamp() << " " << number << " " << name() << " => hello world" << std::endl;
  }
  void TriggerThr()
  {
    // wait();
    trigger.notify(5, sc_core::SC_NS);
    display(__LINE__);
    trigger.notify(4, sc_core::SC_NS);
    display(__LINE__);
    trigger.notify(2, sc_core::SC_NS);
    display(__LINE__);
    // trigger.notify();
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
