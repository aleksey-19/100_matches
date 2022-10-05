#include "mode.h"
#include "read.h"
#include <stdlib.h>
#include <stdio.h>

#define true 1
#define false 0

int mode()
{
  char num_mode[2] = {0};
  int vibor_rejima = 0;
  int vibor_rejima_flag = false;
  while (vibor_rejima_flag == false)
  {
    reading(num_mode);
    vibor_rejima = atoi(num_mode);
    if (vibor_rejima != 1 && vibor_rejima != 2)
    {
      printf ("Нужно выбрать один из режимов!\n");
    }
    else
    {
      vibor_rejima_flag = true;
    }
  }
  return vibor_rejima;
}

