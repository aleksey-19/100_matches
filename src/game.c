#include "game.h"
#include "name_players.h"
#include "read.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define true 1
#define false 0

int matches = 100;
int get = 0;

int smena_hoda = false;
int end_game = false;

char num[60] = {0};

char player_1[60]; char player_2[60];

int mode()
{

  int vibor_rejima = 0;
  int vibor_rejima_flag = false;
  while (vibor_rejima_flag == false)
  {
    reading(num);
    vibor_rejima = atoi(num);
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

int winner (int smena_hoda_num)
{
    if (smena_hoda_num == false)
  {
    printf("Победитель становится %s\n", player_1);
  }
  else
  {
    printf("Победитель становится %s\n", player_2);
  }
  return 0;
}

int mode_computer ()
{
  srand(time(NULL));
  naming (1,player_1,player_2);
  printf ("Вы можете забрать от 1 до 10 спичек,пока их не останется, кто последний вытянет спички, тот победил, тяните спички!\n");
  while(end_game != true)
  {
    if (smena_hoda == false)
    {
      printf ("Спичек осталось %d. Ходит игрок %s",matches, player_1);
      do
      {
        reading(num);
        get = atoi(num);
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
          printf("Не меньше 1 и не больше 10 спичек!!!\n");
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
  winner(smena_hoda);
}

int mode_2_players ()
{
  naming (2,player_1,player_2);
  printf ("Вы можете забрать от 1 до 10 спичек,пока их не останется, кто последний вытянет спички, тот победил, тяните спички!\n");
  while(end_game != true)
  {
    if (smena_hoda == false)
    {
      printf ("Спичек осталось %d. Ходит игрок %s",matches, player_1);
      do
      {
        reading(num);
        get = atoi(num);
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
          printf("Не меньше 1 и не больше 10 спичек!!!\n");
        }
      }
      while(get > 10 || get < 1);
    }
    else
    {
      printf ("Спичек осталось %d. Ходит игрок %s",matches, player_2);
      do
      {
        reading(num);
        get = atoi(num);
        if (get >= 1 && get <=10)
        {
          matches = matches - get;
          if(matches > 0)
          {
            smena_hoda = false;
          }
        }
        else
        {
          printf("Не меньше 1 и не больше 10 спичек!!!\n");
        }
      }
      while(get > 10 || get < 1);
    }
    if (matches == 0)
    {
      end_game = true;
    }
  }
  winner(smena_hoda);
}