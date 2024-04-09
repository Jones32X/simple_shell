#include "simple.h"

/**
 * _myexit - check cmd line for shell exiting
 * @line: command line
 * Return: 0 (Success) otherwise 1 (Fail)
 **/

int _myexit(char *line)
{
	char *exit_lin = "exit";
	int x = 0;
	int length = _strlen(line);

	if (length == 4)
	{
		while (exit_lin[x])
		{
			if (exit_lin[x] != lin[x])
				return (1);
			x++;
		}
		free(line);
		return (0);
	}
	return (1);
}

/**
 * signal_c - Ignore input signal Ctrl + C
 * @sign: siganal parameter
 **/

void signal_c(int sign)
{
	signal(sign, SIG_IGN);
	write(STDOUT_FILENO, "\n#cisfun$ ", 11);
	signal(SIGINT, signal_c);
}

/**
 * _myenv - print the environment variables separated.
 * @line: The command line.
 * @counter: number of entry arguments
 * @argv: entry arguments from main
 * @env: enviroment variables
 * Return: 0 if succes or 1 if fails. 127 if env not found
 **/

int _myenv(char *line, int counter, char **argv, char **env)
{
	char *env_line = "env";
	int i = 0;
	int len = _strlen(line);

	if (len == 3)
	{
		while (env_line[i])
		{
			if (env_line[i] != line[i])
				return (1);
			i++;
		}
		if (env)
		{
			for (i = 0; env[i] != NULL; i++)
				_printf("%s\n", env[i]);
			free(line);
			return (0);
		}
		else
		{
			_printf("%s: %d: env: not found\n", argv[0], counter);
			return (127);
		}
	}
	return (1);
}
