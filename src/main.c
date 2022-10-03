#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define true 1
#define false 0

char player_1[60], player_2[60];

int matches = 100;
int get = 0;

int smena_hoda = false;
int end_game = false;

int main ()
{
  printf ("Добро пожаловать в игру под названием ""100 спичек""!\n\n"
          "Описание игры: из кучки, первоначально содержащей 100 спичек, двое "
          "играющих поочередно берут по несколько спичек: не менее одной и не "
          "более десяти. Выигрывает взявший последнюю(ии) спичку(и).\n\n"
          "Выберите режим игры.\n\n"
          "1. Одиночный\n"
          "2. Вдвоём\n");

  char vibor_rejima_mode = mode ();
  
  if (vibor_rejima_mode == '1')
  {
    mode_computer();
  }
if (vibor_rejima_mode == '2')
  {
    mode_2_players ();
  }
}

int mode_computer ()
{
  srand(time(NULL));
  strcpy (player_2,"Компьютер");
  printf ("Представьтесь пожалуйста:\n");
  scanf ("%s", &player_1);
  printf ("Привет, %s!\n",player_1);

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
  winner();
}

int mode_2_players ()
{
  printf ("Представьтесь пожалуйста, первый игрок:\n");
  scanf ("%s'", &player_1);
  printf ("Привет, %s!\n",player_1);

  printf ("Представьтесь пожалуйста, второй игрок:\n");
  scanf ("%s", &player_2);
  printf ("Привет, %s!\n",player_2);

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
      do
      {
        scanf ("%d",&get);
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
          printf("Не меньше 1 и не больше 10 спичек!!!");
        }
      }
      while(get > 10 || get < 1);
    }
    if (matches == 0)
    {
      end_game = true;
    }
  }
  winner();
}

int mode()
{
  char vibor_rejima = {0};
  int vibor_rejima_flag = false;
  while (vibor_rejima_flag == false)
  {
    scanf ("%c",&vibor_rejima);
    if (vibor_rejima != '1' && vibor_rejima != '2')
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

void winner ()
{
    if (smena_hoda == false)
  {
    printf("Победитель становится %s\n", player_1);
  }
  else
  {
    printf("Победитель становится %s\n", player_2);
  }
  return 0;
}