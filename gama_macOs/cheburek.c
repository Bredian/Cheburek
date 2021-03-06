//
//  cheburek.c
//  chburek
//
//  Created by Александр  Крылов on 9/8/17.
//  Copyright © 2017 Александр  Крылов. All rights reserved.
//
#include<GLUT/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "ai.h"
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <curses.h>
#include <ctype.h>
int fl;
int load_game(FILE * save,char (*field)[9]);
int autosave(FILE * save,char (*field)[9]);
// printing field
int print_field(char (*field)[9]){
    int i,j;
    printf("  1 2 3 4 5 6 7 8 9\n");
    for(i=0;i<9;i++){
        printf("%d ",i+1);
        for(j=0;j<9;j++){
            if(field[i][j]=='x') printf("\033[22;31m%c \033[22;30m",field[i][j]);
            else if(field[i][j]=='o') printf("\033[22;32m%c \033[22;30m",field[i][j]);
            else printf("%c ",field[i][j]);
        }
        printf("\n");
    }
    printf("Select node (h v):\nPrint 0 0 to get to the menu\n");
    return 0;
}
int print_demo(char (*field)[9]){
    int i,j;
    printf("Demo game of cheburek\n");
    printf("  1 2 3 4 5 6 7 8 9\n");
    for(i=0;i<9;i++){
        printf("%d ",i+1);
        for(j=0;j<9;j++){
            if(field[i][j]=='x') printf("\033[22;31m%c \033[22;30m",field[i][j]);
            else if(field[i][j]=='o') printf("\033[22;32m%c \033[22;30m",field[i][j]);
            else printf("%c ",field[i][j]);
        }
        printf("\n");
    }
    return 0;
}
//menu
int menu(FILE *save,char (*field)[9],char * AI,int pid){
    if(system("clear")<0){
        perror("sys error");
        exit(1);
    }
    int answer;
    printf("1 - quit game\n2 - save game\n3 - load game\n4 - credits\n");

    scanf("%d",&answer);
    switch (answer) {
        case 1:
            system("clear");
            printf("Goodbye. See you later.\n");
            kill(pid,SIGKILL);
            system("afplay Quit.wav");
            system("clear");
            exit(0);
            break;
        case 2:
            system("clear");
            autosave(save,field);
            system("clear");
            kill(pid,SIGSTOP);
            printf("Game saved.\n");
            system("afplay Save.wav");
            system("clear");
            kill(pid,SIGCONT);
            break;
        case 3:
            system("clear");
            load_game(save,field);
            system("clear");
            kill(pid,SIGSTOP);
            printf("Game loaded.\n");
            system("afplay Load.wav");
            system("clear");
            kill(pid,SIGCONT);
            break;
        case 4:
            system("clear");
            kill(pid,SIGSTOP);
            printf("Cheburek\nCreated by Bredian\nTetric stategy by Ased\n2017, Dolgop\n");
            system("afplay Credit.mp3");
            system("clear");
            kill(pid,SIGCONT);
            break;
        default:
            break;
    }
    print_field(field);
    return 0;
}

// saving all turns into file
int save_game_log(FILE * log,char (*field)[9]){
    int i,j;
    fprintf(log,"  1 2 3 4 5 6 7 8 9\n");
    for(i=0;i<9;i++){
        fprintf(log,"%d ",i+1);
        for(j=0;j<9;j++){
            fprintf(log,"%c ",field[i][j]);
        }
        fprintf(log,"\n");
    }
    return 0;
}
// save game
int autosave(FILE * save,char (*field)[9]){
    int i,j;

    save=fopen("autosave.txt","r+");
            //Attention! Magic! It is more comfortable to save game in one string
            for(i=0;i<9;i++){
                for(j=0;j<9;j++){
                    fprintf(save,"%c",field[i][j]);
                }
            }
            fclose(save);

    return 0;
}

//load game
int load_game(FILE * save,char (*field)[9]){
    int i,j;
    char symbol;
    for(i=0;i<9;i++){

        for(j=0;j<9;j++){
            symbol=fgetc(save);
            if(symbol=='\n') continue;
            else field[i][j]=symbol;
        }
    }
    return 0;
}
// AI select random node and take turn
int random_strategy_2(char (*field)[9]){
    int i,j,k=0;

    while(k==0 && check_endgame(field)==0){
        i=(rand()%9);
        j=(rand()%9);
        if (field[i][j]=='.') {
            k++;
            field[i][j]='o';
        }
        else continue;
    }
    printf("Last computer turn: %d %d\n",i+1,j+1);
    return 0;
}

int random_strategy_1(char (*field)[9]){
    int i,j,k=0;
    
    while(k==0 && check_endgame(field)==0){
        i=(rand()%9);
        j=(rand()%9);
        if (field[i][j]=='.') {
            k++;
            field[i][j]='x';
        }
        else continue;
    }
    printf("Last computer turn: %d %d\n",i+1,j+1);
    return 0;
}
// Score counting
int score(FILE * log,char (*field)[9]){
    int i,j,x=0,o=0,score_1=0,score_2=0,n=0;
    for(j=0;j<8;j++){
        for(i=0;i<8;i++){
            x=0;
            o=0;
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
    system("clear");
    printf("x player: %d\no player: %d\nno one lands: %d\n",score_1,score_2,n);
    fprintf(log,"x player: %d\no player: %d\nno one lands: %d\n",score_1,score_2,n);
    return 0;
}
//Demo game: Object vs Random
int demo(char (*demo)[9],int status){
    

    printf("\033[1mCheburek game\n\033[22;30m");
    printf("Press enter to continue\n");
    make_turn_1(demo);
    print_demo(demo);
    
    sleep(1);
    system("clear");
    printf("\033[1mCheburek game\n\033[22;30m");
    printf("Press enter to continue\n");
    random_strategy_2(demo);
    print_demo(demo);
    sleep(1);


    system("clear");
    
    return 0;
}

int main(int argc,  char * argv[], char * envp[]) {

    int fd[2];
    mysymb = argv[2];
    int status;
    pipe(fd);
    if(argc==1){
        printf("Need argument to set your apponent AI.\n-r for random AI.\n-o for object based AI.\n");
        printf("Need argument to determine who goes first\n-1 for first turn by computer.\n-2 for first turn for human\n-m for 2 human multiplayer\n-c cXoMpUkTeR FiKhT\n");
        exit(1);
    }
    if(argc==2){
        printf("Need argument to determine who goes first\n-1 for first turn by computer.\n-2 for first turn for human\n-m for 2 human multiplayer\n-c cXoMpUkTeR FiKhT\n");
        exit(1);
    }
    if(strcmp(argv[2],"-c")==0 && argc!=4){
        printf("Please, input ai for second computer\n");
        exit(1);
    }
    system("clear");
    FILE *log = fopen("log.txt", "r+");
    char answer;
    if (log==NULL) printf("Game log error: file does not exists or created\n");
    if (log!=NULL) printf("Game log is OK\n");
    system("afplay logok.wav");
    system("clear");
    int i,j,node,h,v,turn=1;

    srand(time(NULL));
    char field [9][9];
    char demos [9][9];
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            field[i][j]='.';
            demos[i][j]='.';
        }
    }
    int pill = fork();
    if(pill>0){
        int puk = fork();
        if(puk==0){
            while(fl==0){
            demo(demos,fl);
        }
        }
        if(puk>0){
            
            getchar();
            kill(pill,SIGKILL);
            kill(puk,SIGKILL);
        }
        
    }
    if(pill==0){
        execlp("afplay","afplay","Startup.mp3",0);
    }
    //system("afplay Startup.wav");
    system("clear");
    
    FILE *autosaves = fopen("autosave.txt", "r+");
    if (autosaves==NULL) printf("Game save error: file does not exists or created\n");
    if (autosaves!=NULL) printf("Save is OK\n");
    printf("Do you want to load your last game  (y/n)?\n");
    scanf("%c",&answer);
    if(answer=='y' || answer=='Y') {
        load_game(autosaves,field);
    }

    system("clear");
    
    int pid = fork();
    
    if( pid == 0 ){
            int g=rand()%4;
            switch (g) {
                case 0:
                    execlp("afplay","afplay","Gwent1.mp3",0);
                    break;
                case 1:
                    execlp("afplay","afplay","Gwent2.mp3",0);
                    break;
                case 2:
                    execlp("afplay","afplay","Gwent3.mp3",0);
                    break;
                case 3:
                    execlp("afplay","afplay","Gwent4.mp3",0);
                    break;
                default:
                    break;
            }
        

    }
    if(pid>0){
    if(strcmp(argv[2],"-1")==0 && strcmp(argv[1], "-r")==0 && answer=='n') random_strategy_1(field);
    if(strcmp(argv[2],"-1")==0 && strcmp(argv[1], "-o")==0 && answer=='n') make_turn_1(field);
    if(strcmp(argv[2],"-1")==0 && strcmp(argv[1], "-t")==0 && answer=='n') strategy_tetric(field);
    if(strcmp(argv[2],"-c")!=0) print_field(field);
    while(check_endgame(field)==0){
        if(strcmp(argv[2],"-m")!=0 && strcmp(argv[2],"-c")!=0){
            scanf("%d%d",&h,&v);
            if(h==0 || v==0) {
                menu(autosaves,field,argv[1],pid);
                continue;
            }
            else if(field[h-1][v-1]=='.') {
                if(strcmp(argv[2],"-1")==0){
                    field[h-1][v-1]='o';
                    system("afplay Turn.wav");
                }
                else if(strcmp(argv[2],"-2")==0){
                    field[h-1][v-1]='x';
                    system("afplay Turn.wav");
                }

            }
            else {
                printf("Fuck you\n");
                system("afplay Fuck.wav");
                continue;
            }
            system("clear");
            if(strcmp(argv[2],"-1")==0){
                if(strcmp(argv[1],"-o")==0) make_turn_1(field);
                if(strcmp(argv[1],"-r")==0) random_strategy_1(field);
                if(strcmp(argv[1],"-t")==0) strategy_tetric(field);
            }
            else if(strcmp(argv[2],"-2")==0){
                if(strcmp(argv[1],"-o")==0) make_turn_2(field);
                if(strcmp(argv[1],"-r")==0) random_strategy_2(field);
                if(strcmp(argv[1],"-t")==0) strategy_tetric(field);;
            }
            
            print_field(field);
            if(turn==81) fprintf(log,"Turn %d\n",turn);
            else fprintf(log,"Turn %d - %d\n",turn,turn+1);
            save_game_log(log,field);

            turn=turn+2;
            autosave(autosaves,field);
            if(waitpid(pid,&status,WNOHANG)==pid){
                int pin =fork();
                if(pin==0){
                    int g=rand()%4;
                    switch (g) {
                        case 0:
                            execlp("afplay","afplay","Gwent1.mp3",0);
                            break;
                        case 1:
                            execlp("afplay","afplay","Gwent2.mp3",0);
                            break;
                        case 2:
                            execlp("afplay","afplay","Gwent3.mp3",0);
                            break;
                        case 3:
                            execlp("afplay","afplay","Gwent4.mp3",0);
                            break;
                        default:
                            break;
                    }
                }
                if(pin>0){
                    pid=pin;
                }
            }
            char end = check_endgame(field)+'a';
            write(fd[1],&end,1);
            }
        else if(strcmp(argv[2],"-m")==0){
            scanf("%d%d",&h,&v);
            if(h==0 || v==0) {
                menu(autosaves,field,argv[1],pid);
                continue;
            }
            else if(field[h-1][v-1]=='.') {
                    field[h-1][v-1]='x';
                    system("afplay Turn.wav");
            }
            else if(field[h-1][v-1]!='.'){
                printf("Fuck you\n");
                system("afplay Fuck.wav");
               
                continue;
            }
            system("clear");
            print_field(field);
            
            turn=turn+2;
            autosave(autosaves,field);
            
            if(waitpid(pid,&status,WNOHANG)==pid){
                int pin =fork();
                if(pin==0){
                    int g=rand()%4;
                    switch (g) {
                        case 0:
                            execlp("afplay","afplay","Gwent1.mp3",0);
                            break;
                        case 1:
                            execlp("afplay","afplay","Gwent2.mp3",0);
                            break;
                        case 2:
                            execlp("afplay","afplay","Gwent3.mp3",0);
                            break;
                        case 3:
                            execlp("afplay","afplay","Gwent4.mp3",0);
                            break;
                        default:
                            break;
                    }
                }
                if(pin>0){
                    pid=pin;
                }
            }
                scanf("%d%d",&h,&v);
                if(h==0 || v==0) {
                    menu(autosaves,field,argv[1],pid);
                    continue;
                }
                else if(field[h-1][v-1]=='.') {
                    field[h-1][v-1]='o';
                    system("afplay Turn.wav");
                }
                else if(field[h-1][v-1]!='.'){
                    while(field[h-1][v-1]!='.'){
                        printf("Fuck you\n");
                        system("afplay Fuck.wav");
                        scanf("%d%d",&h,&v);
                    }
                    field[h-1][v-1]='o';
                    system("afplay Turn.wav");
                }
            system("clear");
            print_field(field);

            if(turn==81) fprintf(log,"Turn %d\n",turn);
            else fprintf(log,"Turn %d - %d\n",turn,turn+1);
            save_game_log(log,field);
            turn=turn+2;
            autosave(autosaves,field);
            if(waitpid(pid,&status,WNOHANG)==pid){
                int pin =fork();
                if(pin==0){
                    int g=rand()%4;
                    switch (g) {
                        case 0:
                            execlp("afplay","afplay","Gwent1.mp3",0);
                            break;
                        case 1:
                            execlp("afplay","afplay","Gwent2.mp3",0);
                            break;
                        case 2:
                            execlp("afplay","afplay","Gwent3.mp3",0);
                            break;
                        case 3:
                            execlp("afplay","afplay","Gwent4.mp3",0);
                            break;
                        default:
                            break;
                    }
                }
                if(pin>0){
                    pid=pin;
                }
            }
        }
        else if(strcmp(argv[2],"-c")==0){
            system("clear");
            if(strcmp(argv[1],"-o")==0) make_turn_1(field);
            if(strcmp(argv[1],"-r")==0) random_strategy_1(field);
            if(strcmp(argv[1],"-t")==0){
                mysymb="-1";
                strategy_tetric(field);
            }
            print_field(field);
            system("afplay Turn.wav");
            


            
            autosave(autosaves,field);
            if(waitpid(pid,&status,WNOHANG)==pid){
                int pin =fork();
                if(pin==0){
                    int g=rand()%4;
                    switch (g) {
                        case 0:
                            execlp("afplay","afplay","Gwent1.mp3",0);
                            break;
                        case 1:
                            execlp("afplay","afplay","Gwent2.mp3",0);
                            break;
                        case 2:
                            execlp("afplay","afplay","Gwent3.mp3",0);
                            break;
                        case 3:
                            execlp("afplay","afplay","Gwent4.mp3",0);
                            break;
                        default:
                            break;
                    }
                }
                if(pin>0){
                    pid=pin;
                }
            }
            char end = check_endgame(field)+'a';
            write(fd[1],&end,1);
            system("clear");
            if(strcmp(argv[3],"-o")==0) make_turn_2(field);
            if(strcmp(argv[3],"-r")==0) random_strategy_2(field);
            if(strcmp(argv[3],"-t")==0){
                mysymb="-2";
                strategy_tetric(field);
            }
            print_field(field);
            system("afplay Turn.wav");
            
            autosave(autosaves,field);
            
            if(turn==81) fprintf(log,"Turn %d\n",turn);
            else fprintf(log,"Turn %d - %d\n",turn,turn+1);
            save_game_log(log,field);
            turn=turn+2;
            if(waitpid(pid,&status,WNOHANG)==pid){
                int pin =fork();
                if(pin==0){
                    int g=rand()%4;
                    switch (g) {
                        case 0:
                            execlp("afplay","afplay","Gwent1.mp3",0);
                            break;
                        case 1:
                            execlp("afplay","afplay","Gwent2.mp3",0);
                            break;
                        case 2:
                            execlp("afplay","afplay","Gwent3.mp3",0);
                            break;
                        case 3:
                            execlp("afplay","afplay","Gwent4.mp3",0);
                            break;
                        default:
                            break;
                    }
                }
                if(pin>0){
                    pid=pin;
                }
            }

        }
    }
    score(log, field);
    fclose(log);
    fclose(autosaves);
    kill(pid,SIGKILL);
    system("afplay Gamover.wav");
    system("clear");
    }
    return 0;
}

