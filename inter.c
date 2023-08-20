#include "main.h"
/**
 * interactive_mode - function to handle input in interactive mode
 * @av: argv
 */
int interactive_mode(char *av[])
{
	char *line = NULL, *cmd;
	size_t bufsize = BUFFER_SIZE;
	char **args = NULL;
	int exitStatus = 0, counter = 1;
	ssize_t read;

	signal(SIGINT, handle_sigint);
	line = malloc(bufsize);
	if (!line)
	{
		perror("malloc");
		exit(EXIT_FAILURE); }
	while (1)
	{
		write(STDOUT_FILENO, ":> ", 3);
		read = getline(&line, &bufsize, stdin);
		if (read == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(0); }
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
		cmd = _cmd(args[0]);
		if (cmd)
		{
			exitStatus = execute_command(args, line, av, counter,cmd);
		}else {
			_exit_127(av, counter, args);
			free(cmd);
 			free_arguments(args);
			free(line);
			return(127);
		}
		free(cmd);
		free_arguments(args);
		counter++; }
	return (exitStatus); }
