#include "main.h"
char *_cmd(char *command)
{
    struct stat st;
    if (command[0] == '/' || command[0] == '.')
    {
        if (stat(command, &st) == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
        {
            return strdup(command);
        }
        else
        {
            exit(126);
        }
    }
    else
    {
        char *path = search_in_path(command);
        if (path)
        {
            return path;
        }
    }
    return NULL;
}

char **_arguments(char *line)
{
    char **args;
    char *token;
    int i = 0;

    // Allocate memory for the array of pointers
    args = malloc(MAX_ARGS * sizeof(char *));
    if (!args)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \t\n");
    while (token)
    {
        args[i] = strdup(token); // Allocate memory for each argument string
        if (!args[i])
        {
            perror("strdup");
            exit(EXIT_FAILURE);
        }
        i++;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;
    return args;
}


char *search_in_path(char *command)
{
    char *path;
    char *token;
    char *cmd;
    struct stat st;

    path = getenv("PATH");
    if (path == NULL)
        return (NULL);
    if (path[0] == '\0')
        return (NULL);
    token = strtok(path, ":");
    while (token)
    {
        cmd = malloc(strlen(token) + strlen(command) + 2);
        if (!cmd) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        strcpy(cmd, token);
        strcat(cmd, "/");
        strcat(cmd, command);
        if (stat(cmd, &st) == 0) {
            return cmd;
        }
        free(cmd);  // Free memory allocated for cmd
        token = strtok(NULL, ":");
    }
    return NULL;
}
void free_args(char **args)
{
    for (int i = 0; args[i] != NULL; i++) {
        free(args[i]);
    }
    free(args);
}
int is_empty(const char *str)
{
    while (*str != '\0')
    {
        if (!isspace((unsigned char)*str))
        {
            return 0; // Not empty or only spaces
        }
        str++;
    }
    return 1; // Empty or only spaces
}