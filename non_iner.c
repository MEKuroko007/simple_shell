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
	pid_t pid;
	char *cmd;
	int status, exitStatus = 0;
	ssize_t read;
	int counter = 1;
	struct stat st;

	while ((read = getline(&line, &len, stdin)) != -1)
	{
		if (line[read - 1] == '\n')
		{
			line[read - 1] = '\0';
		}

		args = _arguments(line);
		if (!args[0])
		{ counter++;
			free_arguments(args);
			continue; }
		else if (_strcmp(args[0], "exit") == 0)
		{
			exitStatus = exit_shell(args, av, counter, line);
			break; }
        else if (_strcmp(args[0], "env") == 0)
		{
			exitStatus = _env(args);
			free_arguments(args);
			continue; }
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
			}
			else
			{
				free_arguments(args);
				free(cmd);
				free(line);
				exit(127);
			}
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
			{
				exitStatus = WEXITSTATUS(status);
				if (exitStatus == 127)
				{
					char *error_msg;

					error_msg = _not_found(av, counter, args[0]);
					write(2, error_msg, strlen(error_msg));
					free(error_msg);
				}else if (exitStatus == 2)
				{
					free_arguments(args);
					free(cmd);
					free(line);
					exit(2); }}
		}
		free_arguments(args);
		counter++; }
	free(line);
	return (exitStatus);
}
