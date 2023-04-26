#include "shell.h"

/**
 * path_test - checks whether path is valid
 * @path: tokenized path
 * @command: user entered command
 *
 * Return: path appended with command on success
 *         NULL on failure
 */
char *path_test(char **path, char *command)
{
struct stat st;
char *full_path = malloc(PATH_MAX + strlen(command) + 2);
int i;

if (!full_path)
{
return (NULL);
}

for (i = 0; path[i] != NULL; i++)
{
/* concatenate the path and command strings */
strcpy(full_path, path[i]);
strcat(full_path, "/");
strcat(full_path, command);

if (stat(full_path, &st) == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
{
/* command is executable, return full path */
return (full_path);
}
}

free(full_path);
return (NULL);
}
