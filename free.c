#include "main.h"
/**
 * free_arguments - function to free arguemtns
 * @args:arguments
 */
void free_arguments(char **args)
{
	if (args != NULL)
	{
		int i = 0;

		for (; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
	}
}
/**
* handle_sigint - handle ctrl + c
* @sig:signal
*/
void handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}
/**
* cleanup - funtion to clean memory
* @args: arguments
* @cmd: command
*/
void cleanup(char **args, char *cmd)
{
	int i = 0;

	if (cmd)
		free(cmd);

	if (args)
	{
		for (; args[i]; i++)
		{
			free(args[i]);
		}
		free(args);
	}


}
