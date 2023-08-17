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
#include <limits.h>
/**/
int non_interactive_mode(char *av[]);
void interactive_mode(char *av[]);
void handle_sigint(int sig);


/**/
char *_not_found(char *av[], int i, char *cmd);
int _numlen(int n);
void _itos(int n, char *str);
/**/

/***/
char *_cmd(char *command);
char **_arguments(char *buf);
char *search_in_path(char *command);
/**/
int is_empty(const char *str);
void free_arguments(char **args);
void handle_sigint(int sig);
void cleanup(char **args, char *cmd);



/* str1*/
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
/* str2 */
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);
/* str3 */
void rev_string(char *s);
void _memcpy(void *newptr, const void *ptr, unsigned int size);
int _atoi(const char *s);
/**/
int exit_shell(char *args[], char *av[], int counter,char *line);
char *error_exit_shell(char *av[], char *args[], int counter);

#endif /* MAIN_H */
