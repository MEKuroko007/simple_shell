#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024
#define BUF_FLUSH -1
#define MAX_COMMAND_LENGTH 1024
#define MAX_INPUT_SIZE 1024
#define MAX_ARGUMENTS 512
#define MAX_ARGS 20
/****************/
#define MAX_ENV_LEN 100
/************************/
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
#include <limits.h>
#include <fcntl.h>
/**/
int non_interactive_mode(char *av[]);
int interactive_mode(char *av[]);
void handle_sigint(int sig);


/**/
/*char *_not_found(char *av[], int i, char *cmd);*/
int _numlen(int n);
void _itos(int n, char *str);
/**/

/********* cmd ***********/
char *_cmd(char *command);
char **_arguments(char *buf);
char *_path(char *command);
/******* func *******/
int is_empty(const char *str);
void free_arguments(char **args);
void handle_sigint(int sig);
void cleanup(char **args, char *cmd);



/*********** str1 ***********/
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
/********** str2 *************/
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);
/********** str3 **********/
void rev_string(char *s);
void _memcpy(void *newptr, const void *ptr, unsigned int size);
int _atoi(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
size_t _strcspn(const char *str, const char *reject);
/********handle exit*********/
int exit_shell(char *args[], char *av[], int counter, char *line);
int is_valid_integer(const char *str);
/**/
int _env(char *args[]);
int handle_env(char **args, int *exitStatus, int *overwrite);
int _setenv(const char *key, const char *value, int overwrite);
int _unsetenv(const char *key);
char *_getenv(const char *var);

/***********execution**************/
int run_command(char **args, char *av[], int counter, char *line);
int execute_cmd(char **args, char *line, char *av[], int counter, char *cmd);

/********error********/
void _exit_error(char *av[], int counter, char *args[]);
void _exit_127(char *av[], int counter, char *args[]);
void _unknown(char *av[], int counter);



ssize_t _getline(char **lineptr, size_t *n);

/***********File as input***********/
int input_file(const char *filename, char **av);
int exeCommand(char *line, char **av, int counter);
/*********************/


#endif /* MAIN_H */
