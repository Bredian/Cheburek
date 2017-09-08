#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int print_field(char (*field)[9]){
    int i,j;
    printf("  1 2 3 4 5 6 7 8 9\n");
    for(i=0;i<9;i++){
        printf("%d ",i+1);
        for(j=0;j<9;j++){
            printf("%c ",field[i][j]);
        }
        printf("\n");
    }
    printf("Selct node (hv):\n");
    return 0;
}
int check_endgame(char (*field)[9]){
    int i,j,k=0;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(field[i][j]=='.') k++;
        }
    }
    if(k>0) return 0;
    else return 1;
}
int random_strategy(char (*field)[9]){
    int i,j,k=0;
    srand(12);
    while(k==0 && check_endgame(field)==0){
        i=(rand()%9)+1;
        j=(rand()%9)+1;
        if (field[i][j]=='.') {
            k++;
            field[i][j]='o';
        }
        else continue;
    }
    return 0;
}
int score(char (*field)[9]){
    int i,j,x=0,o=0,score_1=0,score_2=0,n=0;
    for(j=0;j<8;j++){
        x=0;
        o=0;
        for(i=0;i<8;i++){
            if(field[i][j]=='x') x++;
            if(field[i][j]=='o') o++;
            if(field[i+1][j]=='x') x++;
            if(field[i+1][j]=='o') o++;
            if(field[i][j+1]=='x') x++;
            if(field[i][j+1]=='o') o++;
            if(field[i+1][j+1]=='x') x++;
            if(field[i+1][j+1]=='o') o++;
            if(x>o) score_1++;
            if(o>x) score_2++;
            if(x==o) n++;
        }

    }
    printf("x player: %d\no player: %d\nno one lands:%d\n",score_1,score_2,n);
    return 0;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int i,j,node,h,v;
    printf("Hello, World!\n");
    char field [9][9];
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            field[i][j]='.';
        }
    }
    print_field(field);
    while(check_endgame(field)==0){
        scanf("%d",&node);
        h=((node-(node%10))/10)-1;
        v=node%10-1;
        if(field[h][v]=='.') field[h][v]='x';
        else {
            printf("Fuck you\n");
            continue;
        }
        random_strategy(field);
        print_field(field);
    }
    score(field);
    return 0;
}
