#include "main.h"
/**
 * _env - prints the evironment variables
 *
 * @args:args
 * Return: 1 on success.
 */
int _env(char *args[])
{
    // (void)line;
	int i, j;

	for (i = 0; environ[i]; i++)
	{

		for (j = 0; environ[i][j]; j++)
			;

		write(STDOUT_FILENO, environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
    // free(args);
    // free(args);
    // free(line);
	// status = 0;

	return (0);
}
/*
*_getenv - function to get the value of env variable
*@name:variable
*/
char *_getenv(const char *name) {
    for (int i = 0; environ[i] != NULL; ++i) {
        // Duplicate the environment string
        char *env = strdup(environ[i]);
        if (env == NULL) {
            perror("Memory allocation failed");
            return NULL;
        }

        // Split the environment variable into name and value
        char *env_name = _strtok(env, "=");
        char *env_value = _strtok(NULL, "=");

        // Check if name matches and return the value
        if (env_name != NULL && env_value != NULL && strcmp(env_name, name) == 0) {
            // Free the duplicated string before returning
            free(env);
            return env_value;
        }

        // Free the duplicated string since no match was found
        free(env);
    }
    return NULL;
}

