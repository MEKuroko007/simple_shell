#include "main.h"
/**
 * non_interactive_mode - function to handle input in non interactive mode
 * @av:arguments
 * Return: STATUS
 */

int non_interactive_mode(char *av[])
{
	char *line = NULL;
	size_t len = 0;
	char **args;
	int exitStatus = 0, counter = 1;
	ssize_t read;

	while ((read = _getline(&line, &len, stdin)) != -1)
	{
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
		args = _arguments(line);
		if (!args[0])
		{
			counter++;
			free_arguments(args);
			continue;
		}
		if (_strcmp(args[0], "exit") == 0)
		{
			exitStatus = exit_shell(args, av, counter, line);
			break;
		} else if (_strcmp(args[0], "env") == 0)
		{
			exitStatus = _env(args);
			continue;
		}
		exitStatus = execute_command(args, line, av, counter);
		free_arguments(args);
		counter++;
	}
	return (exitStatus);
}
