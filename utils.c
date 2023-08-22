#include "main.h"
/**
 * is_valid_integer - check number if integer or not
 * @str:string
 * Return:1 or 0
 */
int is_valid_integer(const char *str)
{
	if (*str == '\0')
		return (0);

	if (*str == '-' || *str == '+')
		str++;

	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}
/**
 * _getenv - check number if integer or not
 * @var:string
 * Return:var or null
 */
char *_getenv(const char *var)
{
	size_t var_len;
	char **env;

	var_len = _strlen(var);
	for (env = environ; *env; ++env)
	{
		if (_strncmp(*env, var, var_len) == 0 && (*env)[var_len] == '=')
		{
			return (&((*env)[var_len + 1]));
		}
	}
	return (NULL);
}
/**
 * _strtok - splits a string by some delimiter.
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: string splited.
 */
char *_strtok(char str[], const char *delim)
{
	static char *split, *str_end;
	char *_start;
	unsigned int i, _bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		split = str;
		i = _strlen(str);
		str_end = &str[i];
	}
	_start = split;
	if (_start == str_end)
		return (NULL);

	for (_bool = 0; *split; split++)
	{
		if (split != _start)
			if (*split && *(split - 1) == '\0')
				break;
		for (i = 0; delim[i]; i++)
		{
			if (*split == delim[i])
			{
				*split = '\0';
				if (split == _start)
					_start++;
				break;
			}
		}
		if (_bool == 0 && *split)
			_bool = 1;
	}
	if (_bool == 0)
		return (NULL);
	return (_start);
}

/**
 * _getline - Read input from stream and assign it to line
 * @line:buffer
 * @len:size
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
