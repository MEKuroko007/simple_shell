#include "main.h"

int main() {
    char command[MAX_COMMAND_LENGTH];
    int status;

    while (1) {
        write(1, ":> ", 3);

        char* line = NULL;
        size_t bufsize = 0;
        ssize_t bytesRead = getline(&line, &bufsize, stdin);

        if (bytesRead == -1) {

            free(line);
            write(1, "\n", 1);
            break;
        }


        line[strcspn(line, "\n")] = '\0';


        strncpy(command, line, MAX_COMMAND_LENGTH);
        command[MAX_COMMAND_LENGTH - 1] = '\0';

        free(line);


        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {

            char* args[MAX_ARGS + 2];
            args[0] = strtok(command, " ");
            int argIndex = 1;

            while (argIndex < MAX_ARGS) {
                args[argIndex] = strtok(NULL, " ");
                if (args[argIndex] == NULL) {
                    break;
                }
                argIndex++;
            }
            args[argIndex] = NULL;
            execve(command, args, NULL);
            perror(command);
            exit(EXIT_FAILURE);
        } else {

            wait(&status);
        }
    }

    return 0;
}
