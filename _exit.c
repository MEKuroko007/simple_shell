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
    int exitStatus;
    int str_len;

    if (args[1] != NULL) {
        exitStatus = _atoi(args[1]);
        str_len = _strlen(args[1]);

        if (!is_valid_integer(args[1]) || str_len > 11)
        {  
            char *error_message = error_exit_shell(av, args, counter);
            if (error_message != NULL) {
                write(2, error_message, _strlen(error_message));
                free(error_message);
            }
            exitStatus = 2;
            free_arguments(args);
            free(line);
            return (2);
        } else if (is_valid_integer(args[1]) && _atoi(args[1]) < 0)
        {
            char *error_message = error_exit_shell(av, args, counter);
            if (error_message != NULL) {
                write(2, error_message, _strlen(error_message));
                free(error_message);
            }
            // write(2,"here\n",5);
            exitStatus = 2;
            free_arguments(args);
            free(line);
            return (2);
        }
        free_arguments(args);
        free(line);
        return(exitStatus % 256);
    }
    /*if (code ==1)
    {
        write(1,":)",2);
        free_arguments(args);
    free(line);
    return (2);
    }*/
    free_arguments(args);
    free(line);
    return (0);
}

/**/
int is_valid_integer(const char *str)
{
    if (*str == '\0') {
        return 0; // Empty string is not a valid integer
    }
    
    if (*str == '-' || *str == '+') {
        str++; // Skip the optional sign character
    }
    
    while (*str != '\0') {
        if (!isdigit(*str)) {
            return 0; // Non-digit character found, not a valid integer
        }
        str++;
    }
    
    return 1; // All characters are digits, valid integer
}

/**/
char *error_exit_shell(char *av[], char *args[], int counter) {
    int length;
    char *error;
    char counter_str[12]; // Assuming _numlen returns up to 11 characters

    length = snprintf(NULL, 0, "%s: %d: %s: Illegal number: %s\n", av[0], counter, args[0], args[1]);
    error = (char *)malloc(length + 1); // Allocate memory for the error message

    if (error != NULL) {
        snprintf(error, length + 1, "%s: %d: %s: Illegal number: %s\n", av[0], counter, args[0], args[1]);
    }

    return error;  // Return the error message (caller should free it)
}
// char *error_exit_shell(char *av[], char *args[], int counter) {
//     int length;
//     char *error;
//     char *shell;

//     length = _strlen(av[0]) + _numlen(counter) + _strlen(args[0]) + 16;
//     error = (char *)malloc(sizeof(char) * (length + 1));
//     if (error == NULL) {
//         return NULL;  // Memory allocation failed
//     }

//     _strcpy(error, av[0]);
//     _strcat(error, ": ");

//     shell = (char *)malloc(sizeof(char) * (_numlen(counter) + 1));
//     if (shell == NULL) {
//         free(error);
//         return NULL;  // Memory allocation failed
//     }
//     _itos(counter, shell);
//     _strcat(error, shell);
//     free(shell);  // Free shell after using it

//     _strcat(error, ": ");
//     _strcat(error, args[0]);
//     _strcat(error, ": Illegal number: ");
//     _strcat(error, args[1]);
//     _strcat(error, "\n");

//     return error;  // Return the error message
// }
