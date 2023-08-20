#include "main.h"
/**
 * execute_command - execute command
 * @args: The arguments for the command.
 * @av: argv from the main program.
 * @counter: A counter variable.
 * @line: The input line.
 * Return: The exit status of the command.
 */
// int execute_command(char **args, char *line, char *av[], int counter)
// {
// 	pid_t pid;
// 	char *cmd;
// 	int status, exitStatus = 0;

// 	pid = fork();
// 	if (pid < 0)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	} else if (pid == 0)
// 	{
// 		cmd = _cmd(args[0]);

// 		if (cmd)
// 		{
// 			if (execve(cmd, args, environ) == -1)
// 			{
// 				perror("execve"); }
// 		} else
// 		{
// 			free_arguments(args);
// 			free(cmd);
// 			free(line);
// 			exit(127); }
// 	} else
// 	{
// 		wait(&status);
// 		if (WIFEXITED(status))
// 		{
// 			exitStatus = WEXITSTATUS(status);
// 			if (exitStatus == 127)
// 			{
// 				_exit_127(av, counter, args); }
// 		}
// 	}
// 	return (exitStatus);
// }
/********************************/

/******************************************/
// int execute_command(char **args, char *line, char *av[], int counter, char *cmd)
// {
// 	pid_t pid;
// 	// char *cmd;
// 	int status, exitStatus = 0;

// 	pid = fork();
// 	if (pid < 0)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	} else if (pid == 0)
// 	{
// 			execve(cmd, args, environ);
// 			perror("execve");
			
// 	} else
// 	{
// 		wait(&status);
// 		if (WIFEXITED(status))
// 		{
// 			exitStatus = WEXITSTATUS(status); }
		
// 	}
// 	return (exitStatus);
// }
	