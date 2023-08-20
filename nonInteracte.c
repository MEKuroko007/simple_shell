#include "main.h"
/**
 * non_interactive_mode - function to handle input in non interactive mode
 * @av:arguments
 * Return: STATUS
 */
int non_interactive_mode(char *av[])
{
	char *line = NULL, **args, *cmd;
	size_t len = 0;
	int exitStatus = 0, counter = 1;
	ssize_t read;

	while ((read = getline(&line, &len, stdin)) != -1)
	{
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
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
			exitStatus = exit_shell(args, av, counter, line);
			break;
		} else if (_strcmp(args[0], "env") == 0)
		{	exitStatus = _env(args);
			continue; }
		cmd = _cmd(args[0]);
		if (cmd)
		{
			exitStatus = execute_cmd(args, line, av, counter, cmd);
		} else
		{	_exit_127(av, counter, args);
			free(cmd);
			free_arguments(args);
			free(line);
			return (127); }
		free(cmd);
		free_arguments(args);
		counter++; }
	free(line);
	return (exitStatus);
}
/**
 * execute_cmd - execute command
 * @args: The arguments for the command.
 * @av: argv from the main program.
 * @counter: A counter variable.
 * @line: The input line.
 * @cmd: command
 * Return: The exit status of the command.
 */
int execute_cmd(char **args, char *line, char *av[], int counter, char *cmd)
{
	pid_t pid;
	int status, exitStatus = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
		if (execve(cmd, args, environ) == -1)
			perror("execve");
	} else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == 0)
				return (0);
			else if (WEXITSTATUS(status) == 2)
				return (2);
			else if (WEXITSTATUS(status) == 127)
				return (127);
		}
	}
	return (0);
}
