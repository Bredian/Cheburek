#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ai.h"
#include <string.h>
int x,y,li=0,ni=0,X,Y;
int make_turn_1(char (* field)[9]){
    int i,j,k=0;
    if(check_endgame(field)==0){
    if(li==0){
    srand(time(NULL));
        while(k==0){
            i=(rand()%7)+1;
            j=(rand()%7)+1;
            if (field[i][j]=='.') {
                k++;
                X=i;
                Y=j;
                li++;
                }
        }
    }
    k=0;
    if(star_check_1(field,X,Y)==1 && field[X][Y]=='.') {
        field[X][Y]='x';
        ni++;
        return 0;
    }
    else if(semistar_check_1(field,X,Y)==1 && field[X][Y]=='.') {
        field[X][Y]='x';
        ni++;
        return 0;
    }
    else if(triangle_check_1(field,X,Y)==1 && field[X][Y]=='.') {
        field[X][Y]='x';
        ni++;
        return 0;
    }
    else if(star_check_1(field,X,Y)==1 && field[X+1][Y]=='.') {
        field[X+1][Y]='x';
        ni++;
        return 0;
    }
    else if(star_check_1(field,X,Y)==1 && field[X-1][Y]=='.') {
        field[X-1][Y]='x';
        ni++;
        return 0;
    }
    else if(star_check_1(field,X,Y)==1 && field[X][Y+1]=='.'){
        field[X][Y+1]='x';
        ni++;
        return 0;
    }
    else if(star_check_1(field,X,Y)==1 && field[X][Y-1]=='.'){
        field[X][Y-1]='x';
        ni++;
        return 0;
    }
    else if(semistar_check_1(field,X,Y)==1 && field[X+1][Y]=='.') {
        field[X+1][Y]='x';
        ni++;
        return 0;
    }
    else if(semistar_check_1(field,X,Y)==1 && field[X-1][Y]=='.') {
        field[X-1][Y]='x';
        ni++;
        return 0;
    }
    else if(semistar_check_1(field,X,Y)==1 && field[X][Y+1]=='.'){
        field[X][Y+1]='x';
        ni++;
        return 0;
    }
    else if(semistar_check_1(field,X,Y)==1 && field[X][Y-1]=='.'){
        field[X][Y-1]='x';
        ni++;
        return 0;
    }
    if(triangle_check_1(field,X,Y)==1 && field[X+1][Y]=='.'){
        field[X+1][Y]='x';
        ni++;
        return 0;
    }
    else if(triangle_check_1(field,X,Y)==1 && field[X-1][Y]=='.') {
        field[X-1][Y]='x';
        ni++;
        return 0;
    }
    else if(triangle_check_1(field,X,Y)==1 && field[X][Y+1]=='.'){
        field[X][Y+1]='x';
        ni++;
        return 0;
    }
    else if(triangle_check_1(field,X,Y)==1 && field[X][Y-1]=='.') {
        field[X][Y-1]='x';
        ni++;
        return 0;
    }

    else if(ni==0 && neutral_check_1(field,X,Y)==1 && field[X+1][Y]=='.') {
        field[X+1][Y]='x';
        return 0;
    }
    else if(ni==0 && neutral_check_1(field,X,Y)==1 && field[X-1][Y]=='.'){
        field[X-1][Y]='x';
        return 0;
    }
    else if(ni==0 && neutral_check_1(field,X,Y)==1 && field[X][Y+1]=='.') {
        field[X][Y+1]='x';
        return 0;
    }
    else if(ni==0 && neutral_check_1(field,X,Y)==1 && field[X][Y-1]=='.') {
        field[X][Y-1]='x';
        return 0;
    }
    else if(ni==0 && neutral_check_1(field,X,Y)==1 && field[X+1][Y+1]=='.') {
        field[X+1][Y+1]='x';
        return 0;
    }
    else if(ni==0 && neutral_check_1(field,X,Y)==1 && field[X-1][Y-1]=='.') {
        field[X-1][Y-1]='x';
        return 0;
    }
    while (k<=81){
        i=(rand()%7)+1;
        j=(rand()%7)+1;
        if(star_check_1(field,i,j)==1 && field[i][j]=='.'){
            X=i;
            Y=j;
            field[i][j]='x';
            return 0;
        }
        k++;
    }
    k=0;
    while (k<=81){
        i=(rand()%9);
        j=(rand()%9);
        if(semistar_check_1(field,i,j)==1 && field[i][j]=='.'){
            X=i;
            Y=j;
            field[i][j]='x';
            return 0;
        }
        k++;
    }
    k=0;
    while (k<=81){
        i=(rand()%9);
        j=(rand()%9);
        if(triangle_check_1(field,i,j)==1 && field[i][j]=='.'){
            X=i;
            Y=j;
            field[i][j]='x';
            return 0;
        }
        k++;
    }
    k=0;
    while (k<=81){
        i=(rand()%9);
        j=(rand()%9);
        if(neutral_check_1(field,i,j)==1 && field[i][j]=='.'){
            X=i;
            Y=j;
            field[i][j]='x';
            return 0;
        }
        k++;
    }
    k=0;
    while(k==0){
        i=(rand()%9);
        j=(rand()%9);
        if (field[i][j]=='.') {
            k++;
            field[i][j]='x';
        }
        else continue;
    }
    ni=0;
    }
    return 0;
    
}

int star_check_1(char (* field)[9],int i, int j){
        if ((field[i][j]=='.' || field[i][j]=='x')  && (field[i+1][j]!='o') && field[i-1][j]!='o' && field[i][j+1]!='o' && field[i][j-1]!='o') return 1;
        else return 0;
}

int semistar_check_1(char (* field)[9],int i, int j){
    if (((field[i][j]=='.' || field[i][j]=='x') && field[i+1][j]!='o' && field[i-1][j]!='o' && field[i][j+1]!='o') || (field[i][j]!='o' && field[i+1][j]!='o' && field[i-1][j]!='o' && field[i][j-1]!='o') || (field[i][j]!='o' && field[i][j+1]!='o' && field[i][j-1]!='o' && field[i+1][j]!='o') || (field[i][j]!='o' && field[i][j+1]!='o' && field[i][j-1]!='o' && field[i-1][j]!='o')) return 1;
    else return 0;
}

int triangle_check_1(char (* field)[9],int i, int j){
    if(((field[i][j]=='.' || field[i][j]=='x') && field[i+1][j]!='o' && field[i][j+1]!='o') || (field[i][j]!='o' && field[i+1][j]!='o' && field[i][j-1]!='o') || (field[i][j]!='o' && field[i-1][j]!='o' && field[i][j+1]!='o') || (field[i][j]!='o' && field[i-1][j]!='o' && field[i][j-1]!='o')) return 1;
    else return 0;
}
int neutral_check_1(char (* field)[9],int i, int j){
    if((field[i][j]!='o' && field[i+1][j]!='o') || (field[i][j]!='o' && field[i-1][j]!='o') || (field[i][j]!='o' && field[i][j+1]!='o') || (field[i][j]!='o' && field[i][j-1]!='o') || (field[i][j]!='o' && field[i+1][j+1]!='o') || (field[i][j]!='o' && field[i-1][j-1]!='o')) return 1;
    else return 0;
}

int make_turn_2(char (* field)[9]){
    int i,j,k=0;
    if(check_endgame(field)==0){
        if(li==0){
            srand(time(NULL));
            while(k==0){
                i=(rand()%7)+1;
                j=(rand()%7)+1;
                if (field[i][j]=='.') {
                    k++;
                    x=i;
                    y=j;
                    li++;
                }
            }
        }
        k=0;
        if(star_check_2(field,x,y)==1 && field[x][y]=='.') {
            field[x][y]='o';
            ni++;
            return 0;
        }
        else if(semistar_check_2(field,x,y)==1 && field[x][y]=='.') {
            field[x][y]='o';
            ni++;
            return 0;
        }
        else if(triangle_check_2(field,x,y)==1 && field[x][y]=='.') {
            field[x][y]='o';
            ni++;
            return 0;
        }
        else if(star_check_2(field,x,y)==1 && field[x+1][y]=='.') {
            field[x+1][y]='o';
            ni++;
            return 0;
        }
        else if(star_check_2(field,x,y)==1 && field[x-1][y]=='.') {
            field[x-1][y]='o';
            ni++;
            return 0;
        }
        else if(star_check_2(field,x,y)==1 && field[x][y+1]=='.'){
            field[x][y+1]='o';
            ni++;
            return 0;
        }
        else if(star_check_2(field,x,y)==1 && field[x][y-1]=='.'){
            field[x][y-1]='o';
            ni++;
            return 0;
        }
        else if(semistar_check_2(field,x,y)==1 && field[x+1][y]=='.') {
            field[x+1][y]='o';
            ni++;
            return 0;
        }
        else if(semistar_check_2(field,x,y)==1 && field[x-1][y]=='.') {
            field[x-1][y]='o';
            ni++;
            return 0;
        }
        else if(semistar_check_2(field,x,y)==1 && field[x][y+1]=='.'){
            field[x][y+1]='o';
            ni++;
            return 0;
        }
        else if(semistar_check_2(field,x,y)==1 && field[x][y-1]=='.'){
            field[x][y-1]='o';
            ni++;
            return 0;
        }
        if(triangle_check_2(field,x,y)==1 && field[x+1][y]=='.'){
            field[x+1][y]='o';
            ni++;
            return 0;
        }
        else if(triangle_check_2(field,x,y)==1 && field[x-1][y]=='.') {
            field[x-1][y]='o';
            ni++;
            return 0;
        }
        else if(triangle_check_2(field,x,y)==1 && field[x][y+1]=='.'){
            field[x][y+1]='o';
            ni++;
            return 0;
        }
        else if(triangle_check_2(field,x,y)==1 && field[x][y-1]=='.') {
            field[x][y-1]='o';
            ni++;
            return 0;
        }
        
        else if(ni==0 && neutral_check_2(field,x,y)==1 && field[x+1][y]=='.') {
            field[x+1][y]='o';
            return 0;
        }
        else if(ni==0 && neutral_check_2(field,x,y)==1 && field[x-1][y]=='.'){
            field[x-1][y]='o';
            return 0;
        }
        else if(ni==0 && neutral_check_2(field,x,y)==1 && field[x][y+1]=='.') {
            field[x][y+1]='o';
            return 0;
        }
        else if(ni==0 && neutral_check_2(field,x,y)==1 && field[x][y-1]=='.') {
            field[x][y-1]='o';
            return 0;
        }
        else if(ni==0 && neutral_check_2(field,x,y)==1 && field[x+1][y+1]=='.') {
            field[x+1][y+1]='o';
            return 0;
        }
        else if(ni==0 && neutral_check_2(field,x,y)==1 && field[x-1][y-1]=='.') {
            field[x-1][y-1]='o';
            return 0;
        }
        while (k<=81){
            i=(rand()%7)+1;
            j=(rand()%7)+1;
            if(star_check_2(field,i,j)==1 && field[i][j]=='.'){
                x=i;
                y=j;
                field[i][j]='o';
                return 0;
            }
            k++;
        }
        k=0;
        while (k<=81){
            i=(rand()%9);
            j=(rand()%9);
            if(semistar_check_2(field,i,j)==1 && field[i][j]=='.'){
                x=i;
                y=j;
                field[i][j]='o';
                return 0;
            }
            k++;
        }
        k=0;
        while (k<=81){
            i=(rand()%9);
            j=(rand()%9);
            if(triangle_check_2(field,i,j)==1 && field[i][j]=='.'){
                x=i;
                y=j;
                field[i][j]='o';
                return 0;
            }
            k++;
        }
        k=0;
        while (k<=81){
            i=(rand()%9);
            j=(rand()%9);
            if(neutral_check_2(field,i,j)==1 && field[i][j]=='.'){
                x=i;
                y=j;
                field[i][j]='o';
                return 0;
            }
            k++;
        }
        k=0;
        while(k==0){
            i=(rand()%9);
            j=(rand()%9);
            if (field[i][j]=='.') {
                k++;
                field[i][j]='o';
            }
            else continue;
        }
        ni=0;
    }
    return 0;
    
}

int star_check_2(char (* field)[9],int i, int j){
    if ((field[i][j]=='.' || field[i][j]=='o')  && (field[i+1][j]!='x') && field[i-1][j]!='x' && field[i][j+1]!='x' && field[i][j-1]!='x') return 1;
    else return 0;
}

int semistar_check_2(char (* field)[9],int i, int j){
    if (((field[i][j]=='.' || field[i][j]=='o') && field[i+1][j]!='x' && field[i-1][j]!='x' && field[i][j+1]!='x') || (field[i][j]!='x' && field[i+1][j]!='x' && field[i-1][j]!='x' && field[i][j-1]!='x') || (field[i][j]!='x' && field[i][j+1]!='x' && field[i][j-1]!='x' && field[i+1][j]!='x') || (field[i][j]!='x' && field[i][j+1]!='x' && field[i][j-1]!='x' && field[i-1][j]!='x')) return 1;
    else return 0;
}

int triangle_check_2(char (* field)[9],int i, int j){
    if(((field[i][j]=='.' || field[i][j]=='o') && field[i+1][j]!='x' && field[i][j+1]!='x') || (field[i][j]!='x' && field[i+1][j]!='x' && field[i][j-1]!='x') || (field[i][j]!='x' && field[i-1][j]!='x' && field[i][j+1]!='x') || (field[i][j]!='x' && field[i-1][j]!='x' && field[i][j-1]!='x')) return 1;
    else return 0;
}
int neutral_check_2(char (* field)[9],int i, int j){
    if((field[i][j]!='x' && field[i+1][j]!='x') || (field[i][j]!='x' && field[i-1][j]!='x') || (field[i][j]!='x' && field[i][j+1]!='x') || (field[i][j]!='x' && field[i][j-1]!='x') || (field[i][j]!='x' && field[i+1][j+1]!='x') || (field[i][j]!='x' && field[i-1][j-1]!='x')) return 1;
    else return 0;
}
// check if game finished
int check_endgame(char (*field)[9]){
    int i,j,k=0;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(field[i][j]=='.') k++;
        }
    }
    if(k>0) {
        k=0;
        return 0;
    }
    else{
        k=0;
        
        return 1;
    }
}
//new function
char symb()
{
    if(strcmp(mysymb,"-1") == 0)
        return 'x';
    if(strcmp(mysymb, "-2") == 0)
        return 'o';
    return 'f';
}

int strategy_tetric(char (* field)[9]) //determine the situation
{
    int i, j, i_max = 0, j_max = 0;
    update_field(field);
    for (i = 0; i < 9; i++)
        for (j = 0; j < 9; j++)
            if (int_field[i][j] > int_field[i_max][j_max])
            {
                i_max = i;
                j_max = j;
            }
    if (int_field[i_max][j_max] > -1)
        field[i_max][j_max] = symb();
    return 0;
}


void update_field(char (*field)[9])
{
    int i, j;
    for (i = 0; i < 9; i++)
        for (j = 0; j < 9; j++)
        {
            if(field[i][j] == 'x' || field[i][j] == 'o')
                {
                    int_field[i][j] = -1;
                    continue;
                }
            if (field[i][j] == '.')
                {
                    if (i % 2 == 1 && j % 2 == 1)
                            int_field[i][j] = int_field[i][j] + 7;

                    int_field[i][j] = int_field[i][j] + analyze_cells (field, i, j);
                    continue;
                }
        }
    return;
}

int analyze_cells (char (*field)[9], int i, int j)
{
    int sum = 0, num_x = 0, num_o = 0;
    if (i - 1 > -1)
    {
        if (j - 1 > -1)
        {
            if (field [i-1][j-1] == 'x') num_x++;
            if (field [i][j-1] == 'x') num_x++;
            if (field [i-1][j] == 'x') num_x++;
            if (field [i][j] == 'x') num_x++;
            if (field [i-1][j-1] == 'o') num_o++;
            if (field [i][j-1] == 'o') num_o++;
            if (field [i-1][j] == 'o') num_o++;
            if (field [i][j] == 'o') num_o++;
            sum = sum + func (num_x, num_o);
            num_x = 0;
            num_o = 0;
        }
        if (j + 1 < 9)
        {
            if (field [i-1][j+1] == 'x') num_x++;
            if (field [i][j+1] == 'x') num_x++;
            if (field [i-1][j] == 'x') num_x++;
            if (field [i][j] == 'x') num_x++;
            if (field [i-1][j+1] == 'o') num_o++;
            if (field [i][j+1] == 'o') num_o++;
            if (field [i-1][j] == 'o') num_o++;
            if (field [i][j] == 'o') num_o++;
            sum = sum + func (num_x, num_o);
            num_x = 0;
            num_o = 0;
        }
    }
    if (i + 1 < 9)
    {
        if (j - 1 > -1)
        {
            if (field [i+1][j-1] == 'x') num_x++;
            if (field [i][j-1] == 'x') num_x++;
            if (field [i+1][j] == 'x') num_x++;
            if (field [i][j] == 'x') num_x++;
            if (field [i+1][j-1] == 'o') num_o++;
            if (field [i][j-1] == 'o') num_o++;
            if (field [i+1][j] == 'o') num_o++;
            if (field [i][j] == 'o') num_o++;
            sum = sum + func (num_x, num_o);
            num_x = 0;
            num_o = 0;
        }
        if (j + 1 < 9)
        {
            if (field [i+1][j+1] == 'x') num_x++;
            if (field [i][j+1] == 'x') num_x++;
            if (field [i+1][j] == 'x') num_x++;
            if (field [i][j] == 'x') num_x++;
            if (field [i+1][j+1] == 'o') num_o++;
            if (field [i][j+1] == 'o') num_o++;
            if (field [i-1][j] == 'o') num_o++;
            if (field [i][j] == 'o') num_o++;
            sum = sum + func (num_x, num_o);
            num_x = 0;
            num_o = 0;
        }
    }
    return sum;
}

int func (int i, int j)
{
    if (i == 0 && j == 0)
        return 2;
    if (i == 0 && j == 1)
        return 2;
    if (i == 0 && j == 2)
        return 1;
    if (i == 1 && j == 0)
        return 3;
    if (i == 1 && j == 1)
        return 4;
    if (i == 1 && j == 2)
        return 2;
    if (i == 2 && j == 0)
        return 5;
    if (i == 2 && j == 1)
        return 6;
    return 0;
}
