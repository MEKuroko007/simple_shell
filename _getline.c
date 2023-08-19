#include "main.h"

/**
 * get_line - Read input from stream and assign it to lineptr
 * @lineptr: Pointer to a buffer that stores the input
 * @n: Pointer to the size of lineptr
 * @stream: Stream to read from
 * Return: The number of bytes read
 */
/*
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t input = 0;
	ssize_t retval = 0;
	int i;
	char t = 'z';
	char *buffer = NULL;
	
	char *new_ptr;

	if (*lineptr == NULL)
	{
		*n = BUFFER_SIZE;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return -1;
	}

	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(*lineptr);
			return -1;
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= *n)
		{
			*n *= 2;
			new_ptr = realloc(*lineptr, *n);
			if (new_ptr == NULL)
			{
				free(*lineptr);
				return -1;
			}
			*lineptr = new_ptr;
		}
		(*lineptr)[input] = t;
		input++;
	}
	(*lineptr)[input] = '\0';
	retval = input;

	if (i != 0)
		input = 0;

	return retval;
}
*/