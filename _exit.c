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

	if (args[1] != NULL)
	{
		exitStatus = _atoi(args[1]);
		str_len = _strlen(args[1]);

		if (!is_valid_integer(args[1]) || str_len > 11)
		{
			char *error_message;

			error_message = error_exit_shell(av, args, counter);
			if (error_message != NULL)
			{
				write(2, error_message, _strlen(error_message));
				free(error_message); }
			exitStatus = 2;
			free_arguments(args);
			free(line);
			return (2);
		} else if (is_valid_integer(args[1]) && _atoi(args[1]) < 0)
		{
			char *error_message;

			error_message = error_exit_shell(av, args, counter);

			if (error_message != NULL)
			{
				write(2, error_message, _strlen(error_message));
				free(error_message); }
			exitStatus = 2;
			free_arguments(args);
			free(line);
			return (2); }
		free_arguments(args);
		free(line);
		return (exitStatus % 256); }
	free_arguments(args);
	free(line);
	return (0); }
