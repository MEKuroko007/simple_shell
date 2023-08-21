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
		path = _path(command);
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

	token = strtok(line, "\n\t\r\a ");
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
		token = strtok(NULL, "\n\t\r\a ");
	}
	args[i] = NULL;
	return (args);
}
/**
 * _path - function to get arguments
 * @command:line
 * Return:arguments
 */
char *_path(char *command)
{
	char *path;
	char *path_copy;
	char *token;
	struct stat st;
	char *cmd;

	path = _getenv("PATH");
	if (!path)
	{
		return (NULL);
	}

	path_copy = _strdup(path);
	if (!path_copy)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	token = _strtok(path_copy, ":");
	while (token)
	{
		cmd = malloc(strlen(token) + _strlen(command) + 2);
		if (!cmd)
		{
			perror("malloc");
			exit(EXIT_FAILURE); }
		_strcpy(cmd, token);
		_strcat(cmd, "/");
		_strcat(cmd, command);
		cmd[_strcspn(cmd, "\r\n")] = '\0';
		if (stat(cmd, &st) == 0)
		{
			free(path_copy);
			return (cmd);
		}
		free(cmd);
		token = _strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
