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
* openFileAsStream - function to read the content of a file
* @filename:name of file
* @mode:mode
* Return:the content
*/

FILE *openFileAsStream(const char *filename, const char *mode)
{
	int fd;
	FILE *file_stream;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (NULL);
	}

	file_stream = fdopen(fd, mode);
	if (file_stream == NULL)
	{
		close(fd);
		return (NULL);
	}

	return (file_stream);
}
/**
* handleCommandFromFile - function to read the content of a file
* @filename:name of file
* @av:arguments
* Return:exit code
*/
int handleCommandFromFile(char *filename, char **av)
{	char *line = NULL, *cmd, **args;
	size_t line_size = 0;
	int exitStatus = 0, counter = 0;
	FILE *file_stream;

	file_stream = openFileAsStream(filename, "r");
	if (file_stream == NULL)
	{	_unknown(av, counter);
		return (2); }
	while (getline(&line, &line_size, file_stream) != -1)
	{	line[strcspn(line, "\n")] = '\0';
		args = _arguments(line);
		if (!args[0])
		{	counter++;
			free_arguments(args);
			continue; }
		if (_strcmp(args[0], "exit") == 0)
		{
			if (exitStatus == 2)
			{	free_arguments(args);
				fclose(file_stream);
				return (2); }
			exitStatus = exit_shell(args, av, counter, line);
			break;
		} else if (_strcmp(args[0], "env") == 0)
		{	exitStatus = _env(args);
			free_arguments(args);
			continue; }
		cmd = _cmd(args[0]);
		if (cmd)
		{	exitStatus = execute_cmd(args, line, av, counter, cmd);
			free(cmd);
		} else
		{	_exit_127(av, counter, args);
			free_arguments(args);
			fclose(file_stream);
			return (127); }
		free_arguments(args);
		counter++; }
	free(line);
	fclose(file_stream);
	return (exitStatus); }
