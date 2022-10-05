#include "name_players.h"
#include "read.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char naming (int mode, char p_1[60], char p_2[60])
{
	if (mode == 1)
	{
		printf ("Представьтесь пожалуйста:\n");
		reading(p_1);
		printf ("Привет, %s",p_1);
		strcpy (p_2, "Компьютер");
	}
	if (mode == 2)
	{
		printf ("Представьтесь пожалуйста, первый игрок:\n");
		reading(p_1);
		printf ("Привет, %s",p_1);
		printf ("Представьтесь пожалуйста, второй игрок:\n");
		reading(p_2);
		printf ("Привет, %s",p_2);
	}
}