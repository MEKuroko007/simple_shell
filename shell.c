#include "main.h"
/**
 * main - entry point of shell
 * @ac:number of arguments
 * @av:arguments
 * Return:exitCode
 */
int main(int ac, char *av[])
{
	int exitCode = 0;

	bool isPiped = !isatty(STDIN_FILENO);
	(void)ac;

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
