#include "shell.h"

/**
 * add_path - concatenates a path and a command
 * @path: the path to the command
 * @command: the command to be added to the path
 *
 * Return: a string containing the concatenated path and command on success,
 *         NULL on failure
 */
char *add_path(char *path, char *command)
{
	size_t path_len, cmd_len;
	char *buf;

	if (path == NULL || command == NULL)
		return (NULL);

	path_len = strlen(path);
	cmd_len = strlen(command);

	buf = malloc(sizeof(char) * (path_len + cmd_len + 2));
	if (buf == NULL)
		return (NULL);

	strcpy(buf, path);

	if (path[path_len - 1] != '/')
		strcat(buf, "/");

	strcat(buf, command);

	return (buf);
}
