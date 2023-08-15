#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024
#define BUF_FLUSH -1
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
#include <sys/stat.h>
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
int non_interactive_mode(char *av[]);
void interactive_mode(void);
/***/
char *_cmd(char *command);
char **_arguments(char *buf);
char *search_in_path(char *command);

int is_empty(const char *str);
void free_args(char **args);



void _puts(char *str);
int _putchar(char c);
void print_error(char *fname, int line_count, char *argv0, char *estr);

#endif /* MAIN_H */
