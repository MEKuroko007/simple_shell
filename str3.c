#include "main.h"

/**
 * _memcpy - copies information between void pointers.
 * @new: destination pointer.
 * @ptr: source pointer.
 * @size: size of the new pointer.
 */
void _memcpy(void *new, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_new = (char *)new;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_new[i] = char_ptr[i];
}
/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 * Return: converted integer
 */
int _atoi(const char *s)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (s[0] == '-')
	{
		sign = -1;
		i++;
	}

	while (s[i] != '\0')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}

	return (sign * result);
}
/**
 * _strncmp - compares two strings to a specified number
 * @s1:first string
 * @s2:second string
 * @n:size
 * Return: 0 if success
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	for (; i < n; ++i)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0')
			return (0);
	}
	return (0);
}
/**
 * _strcspn - remove rejects
 * @str:string
 * @reject:rejects
 * Return:clean string
 */
size_t _strcspn(const char *str, const char *reject)
{
	const char *s;
	const char *r;

	s = str;
	while (*s)
	{
		r = reject;

		while (*r)
		{
			if (*s == *r)
				return (s - str);
			r++;
		}
		s++;
	}
	return (s - str);
}


