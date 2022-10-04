#include <stdio.h>
#include <stdlib.h>

#include "game.h"

#define true 1
#define false 0

char player_1[60], player_2[60];

int main ()
{
  printf ("Добро пожаловать в игру под названием ""100 спичек""!\n\n"
          "Описание игры: из кучки, первоначально содержащей 100 спичек, двое "
          "играющих поочередно берут по несколько спичек: не менее одной и не "
          "более десяти. Выигрывает взявший последнюю(ии) спичку(и).\n\n"
          "Выберите режим игры.\n\n"
          "1. Одиночный\n"
          "2. Вдвоём\n");

  int vibor_rejima_mode = mode ();
  
  if (vibor_rejima_mode == 1)
  {
    mode_computer();
  }
  if (vibor_rejima_mode == 2)
  {
    mode_2_players ();
  }
}