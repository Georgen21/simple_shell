#include "shell.h"


/**
  * _splits_paths - function that splits the path of environment variable.
  * @commd: command with contents of the paths..
  * @copy_commd: Copies command with contents of the paths.
  * Return: An array with splited paths.
  */
char **_splits_paths(char *commd, char *copy_commd)
{
	int bufsize = 1024, post = 0;
	char **tokenize;
	char *tokens;
	char *delim = ":\r\n\a";

	tokenize = malloc(bufsize * sizeof(char *));
	if (!tokenize)
	{
		perror("shell: allocation error\n");
		return (NULL);
	}
	_strcpy(copy_commd, commd);
	if (*copy_commd == *delim)
	{
		*copy_commd = '\0';
		tokenize[post] = copy_commd;
/*		printf("%d: %s\n", post, tokenize[post]);*/
		post++;
	}
	tokens = _strtok(copy_commd, delim);
	while (tokens != NULL)
	{
		tokenize[post] = tokens;
/*		printf("%d: %s\n", post, tokens[post]);*/
		post++;

		if (post >= bufsize)
		{
			bufsize += 1024;
			tokenize = _realloc(tokenize, bufsize - 1024, bufsize * sizeof(char *));
			if (!tokenize)
			{
				perror("shell: allocation error\n");
				return (NULL);
			}
		}
		tokens = _strtok(NULL, delim);
	}
	tokenize[post] = NULL;
	return (tokenize);
}
