#include "mbed.h"

Serial s(USBTX, USBRX, 115200);

void my_callback()
{
  if (s.readable())
  {
    s.getc();
  }
}

int main()
{
  s.attach(callback(&my_callback));
  while(1)
  {
    s.printf("blah\r\n");
    Thread::wait(0.1);
  }
}
