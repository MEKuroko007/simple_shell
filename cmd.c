#include "main.h"
/**
 * _cmd - function to get command
 * @command:command
 * Return:cmd or null
 */
char *_cmd(char *command)
{
	struct stat st;
	char *path;

	if (command[0] == '/' || command[0] == '.')
	{
		if (stat(command, &st) == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
		{
			return (_strdup(command));
		}
		else
		{
			return (NULL);
		}
	}
	else
	{
		path = search_in_path(command);
		if (path)
		{
			return (path);
		}
		else
		{
			return (NULL);
		}
	}
	return (NULL);
}
/**
 * _arguments - function to get arguments
 * @line:line
 * Return:arguments
 */
char **_arguments(char *line)
{
	char **args;
	char *token;
	int i = 0, j = 0;

	args = malloc(MAX_ARGS * sizeof(char *));
	if (!args)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = _strtok(line, " \t\n");
	while (token)
	{
		args[i] = _strdup(token);
		if (!args[i])
		{
			perror("_strdup");
			for (; j < i; j++)
			{
				free(args[j]);
			}
			free(args);
			free(line);
			exit(EXIT_FAILURE);
		}
		i++;
		token = _strtok(NULL, " \t\n");
	}
	args[i] = NULL;
	return (args);
}
/**
 * search_in_path - function to get arguments
 * @command:line
 * Return:arguments
 */
char *search_in_path(char *command)
{
	char *path;
	char *token;
	char *cmd;
	struct stat st;

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);
	if (path[0] == '\0')
		return (NULL);
	token = _strtok(path, ":");
	while (token)
	{
		cmd = malloc(strlen(token) + strlen(command) + 2);
		if (!cmd)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		strcpy(cmd, token);
		strcat(cmd, "/");
		strcat(cmd, command);
		if (stat(cmd, &st) == 0)
		{
			return (cmd);
		}
		free(cmd);
		token = _strtok(NULL, ":");
	}
	return (NULL);
}
/**
 * free_args - free memory
 * @args:arguments
 * Return:1 or 0
 */
void free_args(char **args)
{
	int i = 0;

	for (; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
}
