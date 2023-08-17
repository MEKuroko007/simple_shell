#include "main.h"

/**
 * _not_found - generic error message for command not found
 * @av: arguments to obtain name of program
 * @i: counter
 * @cmd: command
 * Return: Error message
 */
char *_not_found(char *av[], int i, char *cmd)
{
	int length;
	char *error;
	char *shell;

	length = _strlen(av[0]) + _numlen(i) + _strlen(cmd) + 16;
	error = (char *)malloc(sizeof(char) * (length + 1));
	if (error == NULL)
	{
		return NULL;
	}

	_strcpy(error, av[0]);
	_strcat(error, ": ");

	shell = (char *)malloc(sizeof(char) * (_numlen(i) + 1));
	if (shell == NULL)
	{
		free(error); // Free the error message if shell allocation fails
		return NULL;
	}
	_itos(i, shell);
	_strcat(error, shell);

	free(shell); // Free the shell variable once it's no longer needed

	_strcat(error, ": ");
	_strcat(error, cmd);
	_strcat(error, ": not found\n");

	return error;
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
		return 1;
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

	return length;
}
