#include "main.h"
/**
 * _env - prints the evironment variables
 *
 * @args:args
 * Return: 1 on success.
 */
int _env(char *args[])
{
	int i, j;

	for (i = 0; environ[i]; i++)
	{

		for (j = 0; environ[i][j]; j++)
			;

		write(STDOUT_FILENO, environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	free_arguments(args);
	return (0);
}
/**
 * _setenv - set the value of key env
 * @key:variable
 * @value:value of variable
 * @overwrite:overwrite
 * Return: 0 on success.
 */
int _setenv(const char *key, const char *value, int overwrite)
{
	int i;
	char *new_var;
	int new_var_index;

	if (key == NULL || strchr(key, '=') != NULL)
	{
		write(STDERR_FILENO, "_setenv: Invalid variable key\n", 30);
		return (-1);
	}

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], key, _strlen(key)) == 0 &&
				environ[i][_strlen(key)] == '=')
		{
			if (!overwrite)
			{
				return (0);
			}

			snprintf(environ[i], MAX_ENV_LEN, "%s=%s", key, value);
			return (0);
		}
	}

	new_var = (char *)malloc(MAX_ENV_LEN);
	snprintf(new_var, MAX_ENV_LEN, "%s=%s", key, value);

	new_var_index = 0;
	while (environ[new_var_index] != NULL)
	{
		new_var_index++;
	}

	environ[new_var_index] = new_var;
	environ[new_var_index + 1] = NULL;

	return (0);
}
/**
 * _unsetenv - remove the value of key env
 * @key:value of variable
 * Return: 0 on success.
 */
int _unsetenv(const char *key)
{
	int i, j;

	if (key == NULL || strchr(key, '=') != NULL)
	{
		write(STDERR_FILENO, "_unsetenv: Invalid variable key\n", 32);
		return (-1);
	}

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], key, _strlen(key)) == 0 &&
				environ[i][_strlen(key)] == '=')
		{
			free(environ[i]);
			for (j = i; environ[j] != NULL; j++)
			{
				environ[j] = environ[j + 1];
			}
			break;
		}
	}

	return (0);
}

/**
 * handle_env - handle call env - setenv - unsetenv
 * @args:args
 * @exitStatus:args
 * @overwrite:args
 * Return: 0 on success.
 */
int handle_env(char **args, int *exitStatus, int *overwrite)
{
	if (_strcmp(args[0], "env") == 0)
	{
		*exitStatus = _env(args);
		return (0);
	}
	if (_strcmp(args[0], "setenv") == 0)
	{
		if (args[1] && args[2])
		{
			*overwrite = 1;
			_setenv(args[1], args[2], *overwrite);
		}
		else
		{
			*exitStatus = 1;
		}
		free_arguments(args);
		return (0);
	}
	if (_strcmp(args[0], "unsetenv") == 0)
	{
		if (args[1])
		{
			_unsetenv(args[1]);
		}
		else
		{
			*exitStatus = 1;
		}
		free_arguments(args);
		return (0);
	}
	return (-1);
}
