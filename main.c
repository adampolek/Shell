#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "function.h"

#define N 64
#define M 2056

char *pathfile, **history;

volatile sig_atomic_t flag = 1;

void handler(int signum){
    seehistory(history);
    writehis(history, pathfile);
    flag = 0;
    exit(signum);
}


int main(int argv, char *arg[])
{
    int run = 1, i = -1;
    if(argv>1) {
        script(arg[1]);
    }else {
        char *line = (char *) malloc(N * sizeof(char)), **args, cwd[M];
        pathfile = strcat(getenv("PWD"), "/history.txt");
        history = readhis(&i, pathfile);
        ssize_t buffer = N;
        signal(SIGQUIT, handler);

        while (run) {
            getcwd(cwd, sizeof(cwd));
            if (i >= 20)
                i = 0;
            printf("\033[31m\033[1m%s \033[0m:\033[92m\033[1m %s\033[0m:=: ", getenv("USERNAME"), cwd);
            getline(&line, &buffer, stdin);
            history[i] = strdup(line);
            args = divide(line, 0);
            i++;
            run = multiply(args);
        }
        writehis(history, pathfile);
        free(line);
        free(args);
    }
    return 0;
}