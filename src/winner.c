#include <stdio.h>
#include "winner.h"

int winner (int smena_hoda_num, char *player_name_1, char *player_name_2)
{
  if (smena_hoda_num == 0)
  {
    printf("Победитель становится %s\n", player_name_1);
  }
  else
  {
    printf("Победитель становится %s\n", player_name_2);
  }
  return 0;
}