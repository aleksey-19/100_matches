#include "game.h"
#include "name_players.h"
#include "read.h"
#include "mode.h"
#include "winner.h"
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

int start ()
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
    if (matches <= 0)
    {
      end_game = true;
    }
  }
  winner(smena_hoda, player_1, player_2);
  return 0;
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
    if (matches <= 0)
    {
      end_game = true;
    }
  }
  winner(smena_hoda, player_1, player_2);
  return 0;
}