#include "main.h"
/**
 * _unknown - function to print an error
 * @av:arguments
 * @counter:counter
 */
void _unknown(char *av[], int counter)
{
	char count_buffer[12];
	char *countMsg;
	char *file_Msg;
	char *message;
	char *Msg;

	_itos(counter, count_buffer);

	message = av[0];
	write(2, message, strlen(message));

	write(2, ": ", 2);

	countMsg = count_buffer;
	write(2, countMsg, strlen(countMsg));

	write(2, ": ", 2);

	Msg = "cannot open ";
	write(2, Msg, strlen(Msg));
	write(2, av[1], strlen(av[1]));

	write(2, ": ", 2);

	file_Msg = "No such file";
	write(2, file_Msg, strlen(file_Msg));

	write(2, "\n", 1);
}
/**
 * exeCommand - execute commands
 * @line:cmd
 * @av:arguments
 * @counter:counter
 * Return:exit code
 */
int exeCommand(char *line, char **av, int counter)
{
	char **args;
	int exitStatus = 0;
	char *cmd;

	args = _arguments(line);

	if (!args[0])
	{
		counter++;
		free_arguments(args);
		return (exitStatus); }
	if (strcmp(args[0], "exit") == 0)
	{
		if (exitStatus == 2)
		{
			free_arguments(args);
			return (2); }
		exitStatus = exit_shell(args, av, counter, line);
	} else if (strcmp(args[0], "env") == 0)
	{
		exitStatus = _env(args);
	} else
	{
		cmd = _cmd(args[0]);
		if (cmd)
		{
			exitStatus = execute_cmd(args, line, av, counter, cmd);
			free(cmd);
		} else
		{
			_exit_127(av, counter, args);
			exitStatus = 127;
		}
	}

	free_arguments(args);
	counter++;
	return (exitStatus);
}
/**
 * handleCommandFromFile - function to read the content of a file
 * @filename:name of file
 * @av:arguments
 * Return:exit code
 */
int handleCommandFromFile(const char *filename, char **av)
{
	int fd, counter = 0;
	char buff[BUFFER_SIZE];
	ssize_t readBytes;
	ssize_t i = 0, j = 0;
	int exitStatus = 0;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		_unknown(av, counter);
		return (2);
	}
	while ((readBytes = read(fd, buff, sizeof(buff))) > 0)
	{
		for (i = 0; i < readBytes; i++)
		{
			if (buff[i] == '\n')
			{
				buff[j] = '\0';
				if (j > 0)
					exitStatus = exeCommand(buff, av, counter);
				j = 0;
			} else
			{
				buff[j++] = buff[i];
			}
		}
		counter++;

	}
	close(fd);
	return (exitStatus);
}

