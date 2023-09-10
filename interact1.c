#include "shell.h"

/**
 * interact_loop - Returns a pointer to a newly allocated space in memory
 * Return: void.
 */

void interact_loop(void)
{
	char *input;
	char **args;
	int status, length;
	int mode = 1;

	if (isatty(STDIN_FILENO) != 1)
		mode = 0;

	signal(SIGINT, sigint_handler);

	do {
		if (mode != 0)
		{
			/* Print prompt line. */
			length = _strlen("~$ ");
			write(STDOUT_FILENO, "~$ ", length);
		}
		/*Reads from the prompt line (input) */
		input = read_commd_();
		if (input == NULL)
			return;

		/* Split command reads input into arguments. */
		args = splits_txts(input);
		if (args == NULL)
		{
			free(input);
			return;
		}

		/* Executes commands according to arguments. */
		status = exec_work_builtin(args, input);

		/* This frees user input and arguments. */
		free(input);
		free(args);

	} while (status == 1);
}
