#include "main.h"

/**
 * rev_string - reverses a string.
 * @s: input string.
 * Return: no return.
 */
void rev_string(char *s)
{
	int count = 0, i, j;
	char *str, temp;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}
/**
 * _memcpy - copies information between void pointers.
 * @newptr: destination pointer.
 * @ptr: source pointer.
 * @size: size of the new pointer.
 *
 * Return: no return.
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
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
size_t _strcspn(const char *str, const char *reject)
{
    const char *s = str;
    while (*s) {
        const char *r = reject;
        while (*r) {
            if (*s == *r) {
                return s - str; // Return the index where the match is found
            }
            r++;
        }
        s++;
    }
    return s - str; // If no match is found, return the length of the string
}


