#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "shell.h"


/**
* get_full_path - return full path of command
* @cmd: example ls, cd, pwd...
* Return: full path of command or NULL
*/
char *get_full_path(char *cmd, char **env)
{
char *paths = _getenv("PATH", env);
char *path;
char *full_path_cmd;
struct stat st;
int i = 0;
int dynamic_size = 0;

path = strtok(paths, ":");
for (i = 0; path != NULL; i++)
{
dynamic_size = strlen(path) + strlen(cmd) + sizeof(char *) + sizeof(NULL);
full_path_cmd = malloc(dynamic_size);
strcpy(full_path_cmd, path);
strcat(full_path_cmd, "/");
strcat(full_path_cmd, cmd);
if (stat(full_path_cmd, &st) == 0)
{
return (full_path_cmd);
}
free(full_path_cmd);
path = strtok(NULL, ":");
}
return (NULL);
}

/**
* prepare_cmd_path - check if getting full path is needed
* @cmd: the command example ls
* @env: variable env
* Return: full path command
*/
char *prepare_cmd_path(char *cmd, char **env)
{
if (strstr(cmd, "/") != NULL)
return (cmd);
else
return (get_full_path(cmd, env));
}


/**
* extract_args - extract buffer to a list of arguments
* @buffer: input string
* @max_number_of_args: max number of possible args
* Return: pointer to list of arguments
*/
char **extract_args(char *buffer, int max_number_of_args)
{
char *cmd;
char **list_cmd = NULL;
int i = 0;

list_cmd = malloc(max_number_of_args * sizeof(char *));
if (list_cmd == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
cmd = strtok(buffer, " \n\t");
if (cmd == NULL)
return (NULL);
while (cmd != NULL)
{
list_cmd[i] = cmd;
cmd = strtok(NULL, " \n\t");
i++;
}
list_cmd[i] = NULL;

return (list_cmd);
}

/**
<<<<<<< HEAD
* Simple shell 0.2 : Emulate simple terminale with handling arguments
=======
* Simple shell 0.2 : Emulate simple terminale
* with handling arguments
>>>>>>> edb666034bed513d3d62ccdb7bf37ebe675df06c
*/
int main(int ac, char **av, char **env)
{
char *buffer = NULL, *cmd, **list_cmd = NULL;
size_t buffer_size = 0;
int n_char, status, max_number_of_args = 100;
pid_t pid;
(void)ac;
(void)av;

while (1)
{
write(1, "$ ", 2);
n_char = getline(&buffer, &buffer_size, stdin);
if (n_char == EOF)
return (EXIT_FAILURE);
list_cmd = extract_args(buffer, max_number_of_args);
if (list_cmd == NULL)
continue;
if (strcmp(list_cmd[0], "exit") == 0)
exit(0);
if (strcmp(list_cmd[0], "env") == 0)
{
print_env(env);
continue;
}
cmd = prepare_cmd_path(list_cmd[0], env);
if (cmd != NULL)
{
pid = fork();
if (pid == 0)
{
if (execve(cmd, list_cmd, env) == -1)
{
perror("./shell");
return (EXIT_FAILURE);
}
}
else
wait(&status);
}
else
perror("./shell");
free(list_cmd);
}
return (0);
}
