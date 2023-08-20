#include "main.h"

/**
 * _not_found - generic error message for command not found
 * @av: arguments to obtain name of program
 * @i: counter
 * @cmd: command
 * Return: Error message
 */
// char *_not_found(char *av[], int i, char *cmd)
// {
// 	int length;
// 	char *error;
// 	char *shell;

// 	length = _strlen(av[0]) + _numlen(i) + _strlen(cmd) + 16;
// 	error = (char *)malloc(sizeof(char) * (length + 1));
// 	if (error == NULL)
// 	{
// 		return (NULL);
// 	}

// 	_strcpy(error, av[0]);
// 	_strcat(error, ": ");

// 	shell = (char *)malloc(sizeof(char) * (_numlen(i) + 1));
// 	if (shell == NULL)
// 	{
// 		free(error);
// 	}
// 	_itos(i, shell);
// 	_strcat(error, shell);

// 	free(shell);

// 	_strcat(error, ": ");
// 	_strcat(error, cmd);
// 	_strcat(error, ": not found\n");

// 	return (error);
// }
void _exit_127(char *av[], int counter, char *args[])
{
    int i = 0;
    char count_buffer[12];
    char *countMsg;
    char *illegalMsg;
    char *message;

    _itos(counter, count_buffer);

    message = av[0];
    write(2, message, strlen(message));

    write(2, ": ", 2);

    countMsg = count_buffer;
    write(2, countMsg, strlen(countMsg));

    write(2, ": ", 2);

    write(2, args[0], strlen(args[0]));

    write(2, ": ", 2);

    illegalMsg = "not found";
    write(2, illegalMsg, strlen(illegalMsg));

    write(2, "\n", 1);
}
/**
 * _itos - function converts int to string.
 * @n: int number
 * @str: string
 */
void _itos(int n, char *str)
{
	int len = _numlen(n);
	int i = len - 1;

	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return;
	}

	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}

	while (n > 0)
	{
		str[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}

	str[len] = '\0';
}

/**
 * _numlen - Get the length of a number.
 * @n: int number.
 * Return: Length of a number.
 */
int _numlen(int n)
{
	int length = 0;

	if (n == 0)
	{
		return (1);
	}
	else if (n < 0)
	{
		length++;
		n = -n;
	}

	while (n > 0)
	{
		length++;
		n /= 10;
	}

	return (length);
}
