#include "main.h"

/**
 * _getline - Read input from stream and assign it to line
 * @line:buffer
 * @len:size
 * @stream:strem -stdin-
 * Return: bytes
 */
ssize_t _getline(char **line, size_t *len)
{
	ssize_t input = 0;
	ssize_t bytes = 0;
	int i;
	char t = 'z';
	char *ptr;

	if (*line == NULL)
	{	*len = BUFFER_SIZE;
		*line = malloc(*len);
		if (*line == NULL)
			return (-1); }
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(*line);
			return (-1); }
		if (i == 0 && input != 0)
		{
			input++;
			break; }
		if ((size_t)input >= *len)
		{	*len *= 2;
			ptr = realloc(*line, *len);
			if (ptr == NULL)
			{
				free(*line);
				return (-1); }
			*line = ptr; }
		(*line)[input] = t;
		input++;
	}
	(*line)[input] = '\0';
	bytes = input;

	if (i != 0)
		input = 0;
	return (bytes);
}
