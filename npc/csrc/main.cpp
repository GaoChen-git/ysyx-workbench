#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vour_OnOff.h"  //因为创建的是our_OnOff.v 所以头文件要包含Vour_OnOff.h(把V放在前面)
 
 
int main(int argc,char **argv)
{
  Verilated::commandArgs(argc,argv);
  Vour_OnOff *top = new Vour_OnOff("top");
  while(!Verilated::gotFinish())
  {                                                                                                                                 
    int a = rand() & 1;
    int b = rand() & 1;
    top->a = a;
    top->b = b;
    top->eval();
    printf("a = %d, b = %d, f = %d\n",a,b, top->f);
    assert(top->f == a ^ b);
  }
  delete top;
  return 0;
}