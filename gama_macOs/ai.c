#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ai.h"
int x,y,li=0,ni=0,X,Y;
int make_turn_1(char (* field)[9]){
    int i,j,k=0;
    if(check_endgame(field)==0){
    if(li==0){
    srand(time(NULL));
        while(k==0){
            i=(rand()%9);
            j=(rand()%9);
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
                i=(rand()%9);
                j=(rand()%9);
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
