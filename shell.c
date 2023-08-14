#include "main.h"
/**
 * main - entry point
 * @ac:number of arguments
 * @av:arguments
 * Return:0 success
 */
int main(int ac, char *av[])
{
	bool isPiped = !isatty(STDIN_FILENO);
	(void)ac;

	signal(SIGINT, handle_sigint);

	if (isPiped)
	{
		non_interactive_mode(av);
	}
	else
	{
		interactive_mode();
	}

	return (0);
}
