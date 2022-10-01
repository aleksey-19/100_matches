#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define true 1
#define false 0

int main ()
{
  int matches = 100;
  char player_1[60], player_2[60];
  int get = 0;

  printf ("Добро пожаловать в игру под названием ""100 спичек""!\n"
    "Выберите режим игры.\n");
  printf ("1. Одиночный\n");
  printf ("2. Вдвоём\n");

  int vibor_rejima = 0;
  int vibor_rejima_flag = false;
  while (vibor_rejima_flag == false)
  {
    scanf ("%d",&vibor_rejima);
    if (vibor_rejima == 1 || vibor_rejima == 2)
    {
      vibor_rejima_flag = true;
    }
    else
    {
      printf ("Нужно выбрать один из режимов!\n");
    }
  }
  if (vibor_rejima == 1)
  {
    srand(time(NULL));
    strcpy (player_2,"Компьютер");
    printf ("Представьтесь пожалуйста:\n");
    scanf ("'%s[60]'", &player_1);
    printf ("Привет, %s!\n",player_1);

    int smena_hoda = false;
    int end_game = false;

    printf ("Вы можете забрать от 1 до 10 спичек,пока их не останется, кто последний вытянет спички, тот победил, тяните спички!\n");
    while(end_game != true)
    {
      if (smena_hoda == false)
      {
        printf ("Спичек осталось %d. Ходит игрок %s\n",matches, player_1);
        do
        {
          scanf ("%d",&get);
          if (get >= 1 && get <=10)
          {
            matches = matches - get;
            if(matches > 0)
            {
              smena_hoda = true;
            }
          }
          else
          {
            printf("Не меньше 1 и не больше 10 спичек!!!");
          }
        }
        while(get > 10 || get < 1);
      }
      else
      {
        printf ("Спичек осталось %d. Ходит игрок %s\n",matches, player_2);
        if (matches <= 10)
        {
          get = matches;
          matches = matches - get;
        }
        else
        {
          get = rand() % 10 + 1;
          printf ("%d\n",get);
          matches = matches - get;
          smena_hoda = false;
        }
      }
      if (matches == 0)
      {
        end_game = true;
      }
    }
    if (smena_hoda == false)
    {
      printf("Победитель становится %s\n", player_1);
    }
    else
    {
      printf("Победитель становится %s\n", player_2);
    }
  }
  return 0;
}