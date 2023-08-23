#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
* _getenv - return the value of env name
* @name: env name
* Return: env value or NULL
*/
char *_getenv(const char *name, char **environ)
{
char *key;
char *string;

for (; *environ; environ++)
{
string = malloc(strlen(*environ));
strcpy(string, *environ);
key = strtok(string, "=");
if (strcmp(key, name) == 0)
{
return (strtok(NULL, "\n"));
}

}
free(string);
return (NULL);
}

/**
* print_env - print the current env
* @env: environement variables
* Return: void
*/
void print_env(char **env)
{
int i;
for (i = 0; env[i] != NULL; i++)
{
write(1, env[i], strlen(env[i]));
write(1, "\n", 1);
}
}

