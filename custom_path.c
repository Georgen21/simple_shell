#include "shell.h"

/**
  * _checks_path - funtion that splits the line written in the console.
  * @args: argument writen in the console.
  * @flag: flag
  * Return: String with the file path.
  */

char **_checks_path(char **args, int *flag)
{
	char *paths, **tokenize_path, *dest_path, *copy_commd;
	int a, b;

	for (b = 0; *(args[0] + b) != '\0'; b++)
	{
		if (*(args[0] + b) == '/')
			return (args);
	}
	dest_path = malloc(sizeof(char) * 1024);
	if (alloc_errors1_(dest_path) == -1)
		return (NULL);
	paths = _getenv_("PATH"); /*  Gets the path from the env with diff path */
	copy_commd = malloc((_strlen(paths) + 1) * sizeof(char *));
	if (alloc_errors_(copy_commd, dest_path) == -1)
		return (NULL);
	tokenize_path = _splits_paths(paths, copy_commd); /* Get array ptr to path*/
	if (tokenize_path == NULL)
	{ free(copy_commd);
		return (NULL);
	} /* File path (dest_path) add the '/' and the comm */
	for (a = 0; *(tokenize_path + a) != NULL; a++)
	{ _strcpy(dest_path, *(tokenize_path + a));
		if (*dest_path != '\0')
			_strcat(dest_path, "/");
		else
			_strcat(dest_path, "./");
		_strcat(dest_path, args[0]);
		if (access(dest_path, X_OK) != -1) /* Check access rights */
		{ args[0] = dest_path;
			*flag = 1;
			free(copy_commd);
			free(tokenize_path);
			return (args);
		}
	}
	free(dest_path);
	free(tokenize_path);
	free(copy_commd);
	perror("shell");
	return (NULL);
}

/**
 * alloc_errors_ -  function allocates errors
 * @dest_path: the destination path
 * @buf: the buffer
 * Return: -1 on eror.
 */
int alloc_errors_(char *buf, char *dest_path)
{
if (!buf)
	{ free(dest_path);
		perror("shell: allocation error\n");
		return (-1);
	}
		return (0);
}

/**
 * alloc_errors1_ -  function that allocates errors
 * @buf: the buffer
 * Return: -1 on eror.
 */
int alloc_errors1_(char *buf)
{
	if (!buf)
	{ perror("shell: allocation error\n");
		return (-1);
	}
	else
		return (0);
}
