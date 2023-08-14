#include "main.h"

/**
 * extract_arguments - function to get flags
 * @line:buffer
 * @args:arguments
 */
void extract_arguments(char *line, char *args[])
{
	int arg_count = 0;
	char *token = strtok(line, " \t\n");

	while (token != NULL && arg_count < MAX_ARGS - 1)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " \t\n");
	}
	args[arg_count] = NULL;
}
/**
 * exec_cmd_non - function to execute command
 * @av:argv to get name of program
 * @args:flags
 */
void exec_cmd_non(char *av[], char *args[])
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
		char *error_message = _not_found(av, 0, args[0]);

		if (execve(args[0], args, NULL) == -1)
		{
			write(STDERR_FILENO, error_message, _strlen(error_message));
			free(error_message);
			exit(EXIT_FAILURE);
		}
	} else
	{
		waitpid(pid, &status, 0);
	}
}
/**
 * non_interactive_mode - function to handle input in non interactive mode
 * @av:arguments
 */
void non_interactive_mode(char *av[])
{
	char *line = NULL;
	size_t len = 0;

	while (getline(&line, &len, stdin) != -1)
	{
		size_t line_len = _strlen(line);

		if (line_len > 0 && line[line_len - 1] == '\n')
		{
			line[line_len - 1] = '\0';
		}

		if (line[0] != '\0')
		{
			char *args[MAX_ARGS];

			extract_arguments(line, args);

			if (args[0] != NULL && args[0][0] != '\0')
				exec_cmd_non(av, args);
		}
	}

	free(line);
}
