#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int make_turn_1(char (* field)[9]);
int star_check_1(char (* field)[9],int i, int j);
int semistar_check_1(char (* field)[9],int i, int j);
int triangle_check_1(char (* field)[9],int i, int j);
int neutral_check_1(char (* field)[9],int i, int j);

int check_endgame(char (* field)[9]);

int make_turn_2(char (* field)[9]);
int star_check_2(char (* field)[9],int i, int j);
int semistar_check_2(char (* field)[9],int i, int j);
int triangle_check_2(char (* field)[9],int i, int j);
int neutral_check_2(char (* field)[9],int i, int j);

