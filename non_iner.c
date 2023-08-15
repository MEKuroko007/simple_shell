#include "main.h"

/**
 * non_interactive_mode - function to handle input in non interactive mode
 * @av:arguments
 */
int non_interactive_mode(char *av[])
{
    char *line = NULL;
    size_t len = 0;
    char **args;
    pid_t pid;
    char *cmd;
    int status, statusCode;
    ssize_t read;
    int line_number = 1;

    while ((read = getline(&line, &len, stdin)) != -1)
    {
        if (line[read - 1] == '\n')
        {
            line[read - 1] = '\0';
        }

        if (!is_empty(line))
        {
            args = _arguments(line);
            if (args[0]) // Check if there is at least one argument
            {
                pid = fork();
                if (pid < 0)
                {
                    perror("fork");
                    exit(EXIT_FAILURE);
                }
                else if (pid == 0)
                {
                    cmd = _cmd(args[0]);
                    if (cmd)
                    {
                        execve(cmd, args, environ);
                    }
                    else
                    {
                        exit(127);
                    }
                }
                else
                {
                    wait(&status);
                    if (WIFEXITED(status))
                    {
                        statusCode = WEXITSTATUS(status);
                        if (statusCode == 127)
                        {
                            char *error_msg;
                            error_msg = _not_found(av, line_number, args[0]);
                            write(2, error_msg, strlen(error_msg));
                            free(error_msg);
                        }
                    }
                }

                free_args(args);
            }
        }
        line_number++;
    }

    free(line);
    return (0);
}
