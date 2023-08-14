#include "main.h"
/**
 * execute_command - function to execute command
 * @line:buffer
 */
void execute_command(char *line)
{
	pid_t pid = fork();
	int status;

	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{

        char *args[MAX_ARGUMENTS];
        extract_arguments(line, args);

		if (execve(args[0], args, NULL) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
/**
 * interactive_mode - function to handle input in interactive mode
 */
void interactive_mode(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t lines;

	while (1)
	{
		write(STDOUT_FILENO, ":> ", 3);
		lines = getline(&line, &bufsize, stdin);

		if (lines == -1)
		{
			free(line);
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		line[strcspn(line, "\n")] = '\0';
        
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			exit(0);
		}

		if (_strlen(line) > 0)
		{
			execute_command(line);
		}
	}

	free(line);
}