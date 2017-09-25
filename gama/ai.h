#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int make_turn(char (* field)[9]);
int star_check(char (* field)[9],int i, int j);
int semistar_check(char (* field)[9],int i, int j);
int triangle_check(char (* field)[9],int i, int j);
int neutral_check(char (* field)[9],int i, int j);
int check_endgame(char (* field)[9]);
