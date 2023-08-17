#include "main.h"
/**
 * exit_shell - exits the shell
 *
 * @args: arguments passed to the function
 * @av: array of strings representing the command and its arguments
 * @counter: counter value
 * Return: 0 on success.
 */
int exit_shell(char *args[], char *av[], int counter, char *line)
{
    if (args[1] != NULL)
    {
        int status = _atoi(args[1]);
        int str_len = _strlen(args[1]);
        int big_number = status > INT_MAX;

        if (!isdigit(args[1][0]) || str_len > 10 || big_number)
        {
            if (_strcmp("exit", args[0]) == 0)
            {
                char *error_message = error_exit_shell(av, args, counter);
                if (error_message != NULL)
                {
                    write(2, error_message, _strlen(error_message));
                    free(error_message);
                    // exit(0);
                }
                
            }
            return (0);
        }
        free_arguments(args);
        free(line);

        // exit(0);
    }
    free_arguments(args);
    free(line);

    exit(2);

    // return (2);
}

char *error_exit_shell(char *av[], char *args[], int counter)
{
    int length;
    char *error;
    char *shell;

    length = _strlen(av[0]) + _numlen(counter) + _strlen(args[0]) + 16;
    error = (char *)malloc(sizeof(char) * (length + 1));
    if (error == NULL)
    {
        return NULL;
    }

    _strcpy(error, av[0]);
    _strcat(error, ": ");

    shell = (char *)malloc(sizeof(char) * (_numlen(counter) + 1));
    if (shell == NULL)
    {
        free(error);
        return NULL;
    }
    _itos(counter, shell);
    _strcat(error, shell);

    free(shell);

    _strcat(error, ": ");
    _strcat(error, args[0]);
    _strcat(error, ": Illegal number: ");
    _strcat(error, args[1]);
    _strcat(error, "\n");

    return error;
}