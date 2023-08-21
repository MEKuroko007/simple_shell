#include "main.h"
/**
 * _exit_error - error message for exit
 * @counter:counter
 * @av:arguments
 * @args:commands
 */
 /*******************************/
void _exit_error(char *av[], int counter, char *args[])
{
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

	illegalMsg = "Illegal number: ";
	write(2, illegalMsg, strlen(illegalMsg));

	write(2, args[1], strlen(args[1]));

	write(2, "\n", 1);
}

/**
 * _exit_127 - print error msg of 127
 * @av: arguments to obtain name of program
 * @counter: counter
 * @args: arguments
 */
void _exit_127(char *av[], int counter, char *args[])
{
	char count_buffer[12];
	char *countMsg;
	char *NotFound;
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

	NotFound = "not found";
	write(2, NotFound, strlen(NotFound));

	write(2, "\n", 1);
}
/**
 * _unknown - function to print an error
 * @av:arguments
 * @counter:counter
 */
void _unknown(char *av[], int counter)
{
	char count_buffer[12];
	char *countMsg;
	char *file_Msg;
	char *message;
	char *Msg;

	_itos(counter, count_buffer);

	message = av[0];
	write(2, message, strlen(message));

	write(2, ": ", 2);

	countMsg = count_buffer;
	write(2, countMsg, strlen(countMsg));

	write(2, ": ", 2);

	Msg = "cannot open ";
	write(2, Msg, strlen(Msg));
	write(2, av[1], strlen(av[1]));

	write(2, ": ", 2);

	file_Msg = "No such file";
	write(2, file_Msg, strlen(file_Msg));

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
