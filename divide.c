//
// Created by root on 4/23/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "function.h"

#define SIGNS " \n\t\r\a"
#define SIGNSH "\n"
#define N 64

char **divide(char *line, int who);
int multiply(char **args);
void seehistory(char **history);

char **divide(char *line, int who){
    int i = 0;
    char **a = (char**)malloc(N*sizeof(char*));
    if(who == 0){
        a[0] = strtok(line, SIGNS);
        while(a[i] != NULL){
            i++;
            a[i] = strtok(NULL, SIGNS);
        }
    }else{
        a[0] = strtok(line, SIGNSH);
        while(a[i] != NULL){
            i++;
            a[i] = strtok(NULL, SIGNSH);
        }
    }
    return a;
}

int multiply(char **args){
    int i = 0;
    while(args[i] != NULL){
        if(strcmp(args[i], "exit") == 0){
            return 0;
        }
        else if(strcmp(args[i], "cd") == 0){
            if(args[i+1] == NULL){
                chdir(getenv("HOME"));
            }else{
                chdir(args[i+1]);
            }
            return 1;
        }
        else if(strcmp(args[i], "&")==0){
            args[i] = NULL;
            execute(args, 1);
            return 1;
        }
        else if(strcmp(args[i], "|")==0){
            stream(args);
            return 1;
        }else if(strcmp(args[i], ">")==0){
            char *file = args[i+1];
            args[i] = NULL;
            args[i+1] = NULL;
            redirect(args, file, 0);
            return 1;
        }else if(strcmp(args[i], ">>")==0){
            char *file = args[i+1];
            args[i] = NULL;
            args[i+1] = NULL;
            redirect(args, file, 1);
            return 1;
        }
        i++;
    }

    execute(args, 0);

    return 1;
}

void seehistory(char **history){
    int i;
    for(i = 0; i < 20; i++){
        if(history[i][strlen(history[i])-1] == '\n'){
            printf("%d. %s", i+1, history[i]);
        }else{
            printf("\n%d. %s", i+1, history[i]);
        }
    }
}