//
// Created by root on 4/23/18.
//

#ifndef MYSHELL2_FUNCTION_H
#define MYSHELL2_FUNCTION_H

void execute(char **args, int parents);
char **divide(char *line, int who);
int multiply(char **args);
char **readhis(int *number, char *pathfile);
void writehis(char **history, char *pathfile);
void seehistory(char **history);
void stream(char **args);
int script(char *arg);
void redirect(char **args, char *file, int flag);

#endif //MYSHELL2_FUNCTION_H
