#include "main.h"
/*
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
void handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n",1);
	exit(EXIT_FAILURE);
}
void cleanup(char **args, char *cmd)
{
    if (cmd)
    free(cmd);

    if (args)
    {
        for (int i = 0; args[i]; i++)
        {
            free(args[i]);
        }
        free(args);
    }

    
}
