#include "main.h"
/**
 * exit_shell - exits the shell
 * @args: arguments passed to the function
 * @av: array of strings representing the command and its arguments
 * @counter: counter value
 * @line:input
 * Return: 0 on success.
 */
int exit_shell(char *args[], char *av[], int counter, char *line)
{
	int exitStatus;
	int str_len;
	(void)line;

	if (args[1] != NULL)
	{
		exitStatus = _atoi(args[1]);
		str_len = _strlen(args[1]);

		if (!is_valid_integer(args[1]) || str_len > 11)
		{
			 _exit_error(av, counter, args);
			exitStatus = 2;
			free_arguments(args);
		
			return (2);
		} else if (is_valid_integer(args[1]) && _atoi(args[1]) < 0)
		{
			 _exit_error(av, counter, args);
			exitStatus = 2;
			free_arguments(args);
	
			return (2); }
		free_arguments(args);

		return (exitStatus % 256); }
	free_arguments(args);
	/*free(line);*/
	return (0); }
