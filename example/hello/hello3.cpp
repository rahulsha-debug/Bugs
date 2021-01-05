
#include <systemc>

SC_MODULE(hello)
{

  SC_CTOR(hello)
  {
    SC_THREAD(DisplayMth);
  }

  void DisplayMth()
  {
    wait(5, sc_core::SC_NS);
    std::cout << "@@" << sc_core::sc_time_stamp() << " " << name() << " => hello world" << std::endl;
    
  }
};


int sc_main(int argc, char** argv)
{
  hello greet("greet");

  sc_core::sc_start();
  // sc_core::sc_stop();
  return 0;
}
