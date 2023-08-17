#include "main.h"

int main(int ac, char *av[])
{
    int exitCode = 0;

    bool isPiped = !isatty(STDIN_FILENO);
    (void)ac;

    signal(SIGINT, handle_sigint);

    if (isPiped) {
        exitCode = non_interactive_mode(av);
        return exitCode;
    }
    else {
        interactive_mode(av);
        return exitCode;
    }   
    return 0;
}
