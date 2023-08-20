#include "main.h"
/**
 * _exit_error - error message for exit
 * @counter:counter
 * @av:arguments
 * @args:commands
 * Return:Error message
 */
 /*******************************/
void _exit_error(char *av[], int counter, char *args[])
{
    int i = 0;
    char count_buffer[12];
    char *countMsg;
    char *illegalMsg;
    char *message;

    _itos(counter, count_buffer);

    message = av[0];
    write(2, message, strlen(message));

    write(2, ": ", 2);

    countMsg = count_buffer;
    write(2, countMsg, strlen(countMsg));

    write(2, ": ", 2);

    write(2, args[0], strlen(args[0]));

    write(2, ": ", 2);

    illegalMsg = "Illegal number: ";
    write(2, illegalMsg, strlen(illegalMsg));

    write(2, args[1], strlen(args[1]));

    write(2, "\n", 1);
}
