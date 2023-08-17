#include "main.h"
/**
 * _env - prints the evironment variables
 *
 * @args:args
 * Return: 1 on success.
 */
int _env(char *args[])
{
    // (void)line;
	int i, j;

	for (i = 0; environ[i]; i++)
	{

		for (j = 0; environ[i][j]; j++)
			;

		write(STDOUT_FILENO, environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
    // free(args);
    // free(args);
    // free(line);
	// status = 0;

	return (0);
}