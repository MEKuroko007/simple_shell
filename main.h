#ifndef MAIN_H
#define MAIN_H

#define MAX_COMMAND_LENGTH 1024
#define MAX_INPUT_SIZE 1024
#define MAX_ARGUMENTS 512
#define MAX_ARGS 20
extern char **environ;

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stddef.h>
#include <signal.h>
#include <ctype.h>
/**/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void handle_sigint(int sig);
/**/
char *_not_found(char *av[], int i, char *cmd);
int _numlen(int n);
void _itos(int n, char *str);
/**/
void non_interactive_mode(char *av[]);
void interactive_mode(void);
void extract_arguments(char *line, char *args[]);


#endif /* MAIN_H */
