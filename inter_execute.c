#include "main.h"
/**
 * run_command - execute command
 * @args: The arguments for the command.
 * @av: argv from the main program.
 * @counter: A counter variable.
 * @line: The input line.
 * Return: The exit status of the command.
 */
int run_command(char **args, char *av[], int counter, char *line)
{
	pid_t pid;
	char *cmd = NULL;
	int status, exitStatus = 1;

	pid = fork();

	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
		cmd = _cmd(args[0]);
		if (cmd)
		{
			execve(cmd, args, environ);
			perror("execve");
		} else
		{
			cleanup(args, cmd);
			free(line);
			exit(127); }
	} else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			exitStatus = WEXITSTATUS(status);
			// if (exitStatus == 127)
			// {
			// 	char *error_msg;

			// 	error_msg = _not_found(av, counter, args[0]);
			// 	write(STDERR_FILENO, error_msg, _strlen(error_msg));
			// 	free(error_msg); }
		}
		free_arguments(args);
	}
	return (exitStatus);
}


