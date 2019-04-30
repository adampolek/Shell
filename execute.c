//
// Created by root on 4/23/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "function.h"

#define N 64
#define M 1024

void execute(char **args, int parents);
char **readhis(int *number, char *pathfile);
void writehis(char **history, char *pathfile);
void stream(char **args);
int script(char *arg);
void redirect(char **args, char *file, int flag);

void execute(char **args, int parents){
    int status;
    pid_t pid;

    pid = fork();

    if(pid == 0){
        if(execvp(args[0], args) < 0){
            perror("execute");
        }
        exit (EXIT_FAILURE);
    }
    if(parents == 0){
        waitpid(pid, &status, 0);
    }else{
        printf("ID process: %d\n", pid);
    }
}

char **readhis(int *number, char *pathfile){
    char **history, *line = (char*)malloc(M*sizeof(char));
    int f = open(pathfile, O_RDONLY | O_CREAT, 0777);
    int i;
    read(f, line, M);
    history = divide(line, 1);
    for(i = 0; i < 20; i++){
        if(history[i] == NULL){
            if(*number == -1)
                *number = i;
            history[i] = (char*)malloc(N*sizeof(char));
        }
    }
    close(f);
    return history;

}

void writehis(char **history, char *pathfile){
    int f = open(pathfile, O_WRONLY | O_TRUNC);
    int i;

    for(i = 0; i < 20 && history[i] != NULL; i++){
        write(f, history[i], strlen(history[i]));
        if(history[i][strlen(history[i])-1] != '\n'){
            write(f, "\n", strlen("\n"));
        }
    }
    close(f);
}
/*
void stream(char **args) {
    int fds1[2], fds2[2], commend = 1, i = 0, a, b = 0, c, end = 0;
    pid_t pid;
    char **exe = (char **) malloc(N * sizeof(char *));

    while (args[i] != NULL) {
        if (strcmp(args[i], "|") == 0) {
            commend++;
        }
        i++;
    }
    i = 0;

    while (args[i] != NULL && end != 1) {
        a = 0;
        while (strcmp(args[i], "|") != 0) {
            exe[a] = args[i];
            i++;
            a++;
            if(args[i] == NULL){
                end = 1;
                break;
            }
        }
        exe[a] = NULL;
        i++;

        if (b % 2 != 0) {
            pipe(fds1);
        } else {
            pipe(fds2);
        }

        pid = fork();

        if (pid == (pid_t) 0) {
            if (b == 0) {
                dup2(fds2[1], STDOUT_FILENO);
            }else if (b == commend - 1) {
                if (commend % 2 != 0) {
                    dup2(fds1[0], STDIN_FILENO);
                } else {
                    dup2(fds2[0], STDIN_FILENO);
                }

            }else{
                if (b % 2 != 0) {
                    dup2(fds2[0], STDIN_FILENO);
                    dup2(fds1[1], STDOUT_FILENO);
                } else {
                    dup2(fds1[0], STDIN_FILENO);
                    dup2(fds2[1], STDOUT_FILENO);
                }
            }

            c = 0;
            while(exe[c] != NULL) {
                if (strcmp(exe[0], "cd") == 0) {
                    if (exe[1] == NULL) {
                        chdir(getenv("HOME"));
                    } else {
                        chdir(exe[1]);
                    }
                } else if (strcmp(args[i], ">") == 0) {
                    char *file = args[c + 1];
                    args[c] = NULL;
                    args[c + 1] = NULL;
                    redirect(args, file, 0);
                } else if (strcmp(args[c], ">>") == 0) {
                    char *file = args[c + 1];
                    args[c] = NULL;
                    args[c + 1] = NULL;
                    redirect(args, file, 1);
                }
                c++;
            }
            execvp(exe[0], exe);
        }
        if(pid == (pid_t)-1){
            if (b != commend - 1){
                if (b % 2 != 0){
                    close(fds1[1]);
                }else{
                    close(fds2[1]);
                }
            }
            perror("stream");
            return;
        }

        if (b == 0){
            close(fds2[1]);
        }else if (b == commend - 1){
            if (commend % 2 != 0){
                close(fds1[0]);
            }else{
                close(fds2[0]);
            }
        }else{
            if (b % 2 != 0){
                close(fds2[0]);
                close(fds1[1]);
            }else{
                close(fds1[0]);
                close(fds2[1]);
            }
        }
        waitpid(pid,NULL,0);
        b++;
    }
    free(exe);
}
*/
void stream(char **args) {
// File descriptors
	int filedes[2]; // pos. 0 output, pos. 1 input of the pipe
	int filedes2[2];

	int num_cmds = 0;

	char *command[256];

	pid_t pid;

	int err = -1;
	int end = 0;

	// Variables used for the different loops
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;

	// First we calculate the number of commands (they are separated
	// by '|')
	while (args[l] != NULL){
		if (strcmp(args[l],"|") == 0){
			num_cmds++;
		}
		l++;
	}
	num_cmds++;

	// Main loop of this method. For each command between '|', the
	// pipes will be configured and standard input and/or output will
	// be replaced. Then it will be executed
	while (args[j] != NULL && end != 1){
		k = 0;
		// We use an auxiliary array of pointers to store the command
		// that will be executed on each iteration
		while (strcmp(args[j],"|") != 0){
			command[k] = args[j];
			j++;
			if (args[j] == NULL){
				// 'end' variable used to keep the program from entering
				// again in the loop when no more arguments are found
				end = 1;
				k++;
				break;
			}
			k++;
		}
		// Last position of the command will be NULL to indicate that
		// it is its end when we pass it to the exec function
		command[k] = NULL;
		j++;

		// Depending on whether we are in an iteration or another, we
		// will set different descriptors for the pipes inputs and
		// output. This way, a pipe will be shared between each two
		// iterations, enabling us to connect the inputs and outputs of
		// the two different commands.
		if (i % 2 != 0){
			pipe(filedes); // for odd i
		}else{
			pipe(filedes2); // for even i
		}

		pid=fork();

		if(pid==-1){
			if (i != num_cmds - 1){
				if (i % 2 != 0){
					close(filedes[1]); // for odd i
				}else{
					close(filedes2[1]); // for even i
				}
			}
			printf("Child process could not be created\n");
			return;
		}
		if(pid==0){
			// If we are in the first command
			if (i == 0){
				dup2(filedes2[1], STDOUT_FILENO);
			}
			// If we are in the last command, depending on whether it
			// is placed in an odd or even position, we will replace
			// the standard input for one pipe or another. The standard
			// output will be untouched because we want to see the
			// output in the terminal
			else if (i == num_cmds - 1){
				if (num_cmds % 2 != 0){ // for odd number of commands
					dup2(filedes[0],STDIN_FILENO);
				}else{ // for even number of commands
					dup2(filedes2[0],STDIN_FILENO);
				}
			// If we are in a command that is in the middle, we will
			// have to use two pipes, one for input and another for
			// output. The position is also important in order to choose
			// which file descriptor corresponds to each input/output
			}else{ // for odd i
				if (i % 2 != 0){
					dup2(filedes2[0],STDIN_FILENO);
					dup2(filedes[1],STDOUT_FILENO);
				}else{ // for even i
					dup2(filedes[0],STDIN_FILENO);
					dup2(filedes2[1],STDOUT_FILENO);
				}
			}

			if (execvp(command[0],command)==err){
				kill(getpid(),SIGTERM);
			}
		}

		// CLOSING DESCRIPTORS ON PARENT
		if (i == 0){
			close(filedes2[1]);
		}
		else if (i == num_cmds - 1){
			if (num_cmds % 2 != 0){
				close(filedes[0]);
			}else{
				close(filedes2[0]);
			}
		}else{
			if (i % 2 != 0){
				close(filedes2[0]);
				close(filedes[1]);
			}else{
				close(filedes[0]);
				close(filedes2[1]);
			}
		}

		waitpid(pid,NULL,0);

		i++;
	}
}


    int script(char *arg) {
        int f = open(arg, O_RDONLY), i = 1;
        char *buffer = (char *) malloc(M * sizeof(char)), **args, **line;
        read(f, buffer, M);
        line = divide(buffer, 1);
        while (line[i] != NULL) {
            args = divide(line[i], 0);
            multiply(args);
            i++;
        }
        free(buffer);
        free(line);
        free(args);
        close(f);
        return 0;
    }

    void redirect(char **args, char *file, int flag) {
        pid_t pid;
        pid = fork();

        if (pid == (pid_t) 0) {
            close(1);
            int f;
            if (flag == 0) {
                f = open(file, O_WRONLY | O_TRUNC, 0644);
            }
            if (flag == 1) {
                f = open(file, O_WRONLY | O_APPEND | O_CREAT, 0644);
            }
            dup2(f, STDIN_FILENO);
            execvp(args[0], args);
            close(f);

        }

    }