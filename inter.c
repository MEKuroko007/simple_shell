#include "main.h"
/**
 * interactive_mode - function to handle input in interactive mode
 */
/**
 * interactive_mode - function to handle input in interactive mode
 */
void interactive_mode(void)
{
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t lines;
    char **args;
    char *cmd;
    pid_t pid;
    int status;

    while (1)
    {
        write(STDOUT_FILENO, ":> ", 3);
        lines = getline(&line, &bufsize, stdin);
        if (lines == -1)
        {
            write(1, "\n", 1);
            exit(1);
        }
		if (line[lines - 1] == '\n') {
            line[lines - 1] = '\0';
        }

        // Skip processing if the line is empty or contains only spaces
        if (is_empty(line)) {
            continue;
        }
        args = _arguments(line);
        pid = fork();

        if (strcmp(args[0], "exit") == 0)
        {
            // Free memory allocated for arguments
            for (int i = 0; args[i] != NULL; i++) {
                free(args[i]);
            }
            free(args);
            
            free(line);
            exit(0);
        }
        if (pid < 0)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {

            cmd = _cmd(args[0]);
            if (cmd) {
                execve(cmd, args, environ);
                perror("execve"); // In case execve fails
            }
            else
                printf("not found");
            exit(0);
        }
        else
        {
            wait(&status);
        }

        // Free memory allocated for arguments
        free_args(args);
    }

    free(line);
}
