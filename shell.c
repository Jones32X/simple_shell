#include "simple.h"

/**
 * main - Entry point for shell
 * @argc: Number of arguments
 * @argv: string of arguments
 * @env: enviromet var
 * Return: 0 (Return value)
 */

int main(int __attribute__((unused))argc, char **argv, char **env)
{
	int status_output = 0, rd = 1, cnter = 0;

	while (rd)
	{
		char *command_line = NULL, **argm = NULL;
		size_t line_size = 0;

		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "#cisfun$ ", 10);
		signal(SIGINT, signal_c);
		rd = getline(&command_line, &line_size, stdin);
		if (rd < 0)
		{
			free(command_line);
			exit(status_output);
		}
		if (rd == 1)
		{
			free(command_line);
			continue;
		}
		if (rd != EOF)
		{
			cnter++;
			_strtok(command_line, "\n");
			if (_myexit(command_line) == 0)
				return (status_output);
			if (_myenv(command_line, cnter, argv, env) == 0)
				continue;
			argm = splitline(command_line);
			if (argm[0] == NULL)
			{
				free(command_line), free(argm);
				continue;
			}
			status_output = execute_process(argm, argv, cnter);
		}
		free(command_line), free(argm);
	}
	return (status_output);
}
