#include "main.h"
/**
 * main - entry point of shell
 * @ac:number of arguments
 * @av:arguments
 * Return:exitCode
 */
int main(__attribute__((unused))int ac, char **av)
{
	int exitCode = 0;

	bool isPiped = !isatty(STDIN_FILENO);

	if (av[1] != NULL)
		return handleCommandFromFile(av[1],av);
	signal(SIGINT, handle_sigint);

	if (isPiped)
	{
		exitCode = non_interactive_mode(av);
		return (exitCode);
	}
	else
	{
		exitCode = interactive_mode(av);
		return (exitCode);
	}
	return (0);
}
