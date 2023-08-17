#include "main.h"
/**
 * interactive_mode - function to handle input in interactive mode
 */

void interactive_mode(char *av[]) {
    char *line = NULL;
    size_t bufsize = BUFFER_SIZE;
    char **args = NULL;
    char *cmd = NULL;
    pid_t pid;
    int status, exitStatus = 1;
    int counter = 1;

    signal(SIGINT, handle_sigint); // Set up signal handler

    line = malloc(bufsize);
    if (!line) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    ssize_t lines;
    while (1)
    {
        write(STDOUT_FILENO, ":> ", 3);
        lines = getline(&line, &bufsize, stdin);
        if (lines == -1) {
            write(STDOUT_FILENO, "\n", 1);
            // free(line);
            // free(args);
            exit(0);
        }
        if (line[lines - 1] == '\n') {
            line[lines - 1] = '\0';
        }

        if (!line[0]) {
            continue;
        }
        args = _arguments(line);
        if (strcmp(args[0], "exit") == 0)
        {
            exitStatus = exit_shell(args, av, counter,line);
            // free_arguments(args);
            // free(line);
            // free(cmd);
            break;
        }else if (_strcmp(args[0], "env") == 0)
		{
			exitStatus = _env(args);
            // free(line);
            free_arguments(args);
			continue; }
        pid = fork();

        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            cmd = _cmd(args[0]);
            if (cmd) {
                execve(cmd, args, environ);
                perror("execve");
            } else {
                cleanup(args, cmd);
                free(line);
                exit(127);
            }
        } else {
            wait(&status);
            if (WIFEXITED(status)) {
                exitStatus = WEXITSTATUS(status);
                if (exitStatus == 127) {
                    char *error_msg;
                    error_msg = _not_found(av, counter, args[0]);
                    write(STDERR_FILENO, error_msg, _strlen(error_msg));
                    free(error_msg);
                }
                // }else if(exitStatus == 2)
                // {
                //     write(2,"er",2);
                // }
            }
            free_arguments(args);
        }
    }
    free(line);
}

