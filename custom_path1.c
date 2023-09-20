#include "shell.h"


/**
  * _splits_paths - function that splits the path of environment variable.
  * @commd: command with contents of the paths..
  * @copy_commd: Copies command with contents of the paths.
  * Return: An array with splited paths.
  */
char **_splits_paths(char *commd, char *copy_commd)
{
	int contsize = 1024, track = 0;
	char **tokenize;
	char *token;
	char *delimeter = ":\r\n\a";

	tokenize = malloc(contsize * sizeof(char *));
	if (!tokenize)
	{
		perror("shell: allocation error\n");
		return (NULL);
	}
	_strcpy(copy_commd, commd);
	if (*copy_commd == *delimeter)
	{
		*copy_commd = '\0';
		tokenize[track] = copy_commd;
	/*printf("%d: %s\n", track, tokenize[track]);*/
		track++;
	}
	token = _strtok(copy_commd, delimeter);
	while (token != NULL)
	{
		tokenize[track] = token;
/*		printf("%d: %s\n", track, tokens[track]);*/
		track++;

		if (track >= contsize)
		{
			contsize += 1024;
			tokenize = _realloc(tokenize, contsize - 1024, contsize * sizeof(char *));
			if (!tokenize)
			{
				perror("shell: allocation error\n");
				return (NULL);
			}
		}
		token = _strtok(NULL, delimeter);
	}
	tokenize[track] = NULL;
	return (tokenize);
}
