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
 * _getenv - function to get the value of env variable
 * @name:variable
 * Return:value or null
 */
// char *_getenv(const char *name)
// {
// 	int i = 0;
// 	char *env;
// 	char *env_name;
// 	char *env_value;

// 	for (; environ[i] != NULL; ++i)
// 	{
// 		env = strdup(environ[i]);
// 		if (env == NULL)
// 		{
// 			perror("Memory allocation failed");
// 			return (NULL); }
// 		env_name = _strtok(env, "=");
// 		env_value = _strtok(NULL, "=");
// 		if (env_name != NULL && env_value != NULL && strcmp(env_name, name) == 0)
// 		{
// 			free(env);
// 			return (env_value); }
// 		free(env);
// 	}
// 	return (NULL);
// }
