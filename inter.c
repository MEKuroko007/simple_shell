#include "main.h"
/**
 * interactive_mode - function to handle input in interactive mode
 * @av: argv
 * Return: code status
 */
int interactive_mode(char *av[])
{
	char *line = NULL, **args, *cmd;
	size_t len = 0;
	/*size_t bufsize = BUFFER_SIZE;*/
	int exitStatus = 0, counter = 1, overwrite;
	ssize_t bytes;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		bytes = _getline(&line, &len);
		if (bytes == -1)
		{	write(STDOUT_FILENO, "\n", 1);
			exit(0); }
		if (line[bytes - 1] == '\n')
			line[bytes - 1] = '\0';
		args = _arguments(line);
		if (!args[0])
		{	counter++;
			free_arguments(args);
			continue; }
		if (_strcmp(args[0], "exit") == 0)
		{
			if (exitStatus == 2)
			{	free_arguments(args);
				free(line);
				return (2); }
			free(line);
			exitStatus = exit_shell(args, av, counter, line);
			break; }
		if (handle_env(args, &exitStatus, &overwrite) == 0)
		{ continue; }
		cmd = _cmd(args[0]);
		if (cmd)
		{	exitStatus = execute_cmd(args, line, av, counter, cmd);
			free_arguments(args); }
		else
		{	_exit_127(av, counter, args);
			free_arguments(args); }
		free(cmd);
		counter++; }
	return (exitStatus); }
