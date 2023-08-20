#include "main.h"
int readFIle(char **av)
{
    int fileDescriptor;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    fileDescriptor = open(av[1], O_RDONLY);
    if (fileDescriptor == -1) {
        perror("Error opening file");
        return 1;
    }

  
    while ((bytesRead = read(fileDescriptor, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytesRead);
    }


    close(fileDescriptor);

    return 0;
}