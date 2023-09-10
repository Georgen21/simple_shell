#include "shell.h"

/**
  * _launch - function starts the process to be executed.
  * @args: List of arguments passed.
  * Return: Always 1.
  */
int _launch(char **args)
{
	int state, pid;
	int flag = 0;

	args = _checks_path(args, &flag);

	if (args == NULL)
		return (1);

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("shell:");
		}
		if (flag == 1)
			free(args[0]);
		return (-1);
	}
	else if (pid < 0)
	{
		perror("shell:");
		if (flag == 1)
			free(args[0]);
		return (-1);

	}
	else
	{
		do {
			waitpid(pid, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}
	if (flag == 1)
		free(args[0]);
	return (1);
}
