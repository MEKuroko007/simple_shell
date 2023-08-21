#include "main.h"

int _setenv(const char *key, const char *value, int overwrite)
{
  int i;
  char *new_var;
  int new_var_index;

  if (key == NULL || strchr(key, '=') != NULL) {
    write(STDERR_FILENO, "_setenv: Invalid variable key\n", 30);
    return -1;
  }

  for (i = 0; environ[i] != NULL; i++) {
    if (_strncmp(environ[i], key, _strlen(key)) == 0 &&
        environ[i][_strlen(key)] == '=') {
      if (!overwrite) {
        return 0;
      }

      snprintf(environ[i], MAX_ENV_LEN, "%s=%s", key, value);
      return 0;
    }
  }

  new_var = (char *)malloc(MAX_ENV_LEN);
  snprintf(new_var, MAX_ENV_LEN, "%s=%s", key, value);

  new_var_index = 0;
  while (environ[new_var_index] != NULL) {
    new_var_index++;
  }

  environ[new_var_index] = new_var;
  environ[new_var_index + 1] = NULL;

  return 0;
}

int _unsetenv(const char *key)
{
  int i, j;

  if (key == NULL || strchr(key, '=') != NULL) {
    write(STDERR_FILENO, "_unsetenv: Invalid variable key\n", 32);
    return -1;
  }

  for (i = 0; environ[i] != NULL; i++) {
    if (strncmp(environ[i], key, _strlen(key)) == 0 &&
        environ[i][_strlen(key)] == '=') {
      free(environ[i]);
      for (j = i; environ[j] != NULL; j++) {
        environ[j] = environ[j + 1];
      }
      break;
    }
  }

  return 0;
}
