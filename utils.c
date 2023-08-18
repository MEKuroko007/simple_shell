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
    size_t var_len = _strlen(var);
    for (char **env = environ; *env; ++env)
	{
        if (_strncmp(*env, var, var_len) == 0 && (*env)[var_len] == '=')
		{
            return &((*env)[var_len + 1]);
        }
    }
    return (NULL);
}