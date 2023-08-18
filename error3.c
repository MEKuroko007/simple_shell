#include "main.h"
/**
 * error_exit_shell - handle exit
 * @av:arguments
 * @args:input
 * @counter:number
 * Return:error
 */
char *error_exit_shell(char *av[], char *args[], int counter)
{
	int length;
	char *error;
	/*char counter_str[12];*/

	length = snprintf(NULL, 0, "%s: %d: %s: Illegal number: %s\n", av[0], counter, args[0], args[1]);
	error = (char *)malloc(length + 1);
	if (error != NULL)
		snprintf(error, length + 1, "%s: %d: %s: Illegal number: %s\n", av[0], counter, args[0], args[1]);

	return (error);
}