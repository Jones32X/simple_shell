#include "simple.h"

/**
 * _getenv - find the env vari. name
 * @name: variable name
 * Return: NULL if fails or pointer to value of env.var.
*/

char *_getenv(const char *name)
{
	int b = 0;
	int i = 0;
	char *a;
	char *copy;

	for (; environ[i] != NULL ; i++)
	{
		for (; name[b] == environ[i][b] && name[b] != '\0' ; b++)
		{
			if (name[b + 1] == '\0')
			{
				a = &environ[i][b + 2];
				copy = malloc(sizeof(char) * _strlen(a) + 1);

				if (!copy)
					return (NULL);

				copy = _strcpy(copy, a);
				return (copy);
			}
		}
	}
	return (NULL);
}
/**
 * _getline - get line command line from the prompt
 * @bufline: command buffer line string.
 * @size: size of the command buffer lines.
 * @std: file stream where comes the command buffer line.
 * Return: number of bytes copied in the buffer.
 **/
ssize_t _getline(char **bufline, size_t *size, FILE *std)
{
	size_t count;
	size_t alloc = 1024;
	char c;

	count = 0;

	if (!bufline || !size || !std)
		return (-1);
	if (*bufline == NULL)
	{
		*bufline = malloc(alloc);
		if (!(*bufline))
			return (-1);
	}
	while ((c = _getchar()) != EOF)
	{
		if (c == '\n')
		{
			count++;
			break;
		}
		count++;
		(*bufline)[count - 1] = c;
	}
	if (c == EOF)
	{
		return (-1);
	}
	(*bufline)[count] = '\0';
	return (count);
}
/**
* splitline - get line command line from the prompt
* @command_line: command line string.
* Return: a pointer to string of command strings.
**/
char **splitline(char *command_line)
{
	char **ptrstr;
	int size;
	int pos;
	char *word;

	pos = 0;
	size = 100;

	ptrstr = malloc(sizeof(char *) * size);
	if (ptrstr == NULL)
		exit(EXIT_FAILURE);
	word = _strtok(command_line, " ");
	while (word != NULL)
	{
		ptrstr[pos++] = word;
		word = _strtok(NULL, " ");
	}
	ptrstr[pos] = NULL;
	return (ptrstr);
}

/**
 * execute_process - proces function execute
 * @argm: arguments from line of command
 * @argv: string of arguments
 * @counter: number of ecution processes
 * Return: 0 (Success) -1 (Failed)
 **/

int execute_process(char **argm, char **argv, int counter)
{
	pid_t child_process;
	int status_output;
	int status;
	char *buffer = NULL;
	char *command_path = NULL;

	status_output = 0;

	command_path = check_path(argm[0]);
	if (command_path == NULL)
	{
		buffer = execute_command(argm[0]);
		if (buffer == NULL)
		{
			_printf("%s: %d: %s: not found\n", argv[0], counter, argm[0]);
			free(buffer);
			return (1);
		}
	}
	child_process = fork();
	if (child_process < 0)
		exit(errno);
	else if (child_process == 0)
	{
		if (command_path != NULL)
		{
			if (execve(command_path, argm, environ) == -1)
				exit(errno);
		}
		if (execve(buffer, argm, environ) == -1)
			exit(errno);
	}

	wait(&status);
	if (WIFEXITED(status))
		status_output = WEXITSTATUS(status);
	free(buffer);

	return (status_output);
}

/**
 * _which - search  command in the directories
 * @head: head
 * @av: arguments
 * Return: path of a command or null
 **/

char *_which(link_t **head, char *av)
{
	link_t *pusher = *head;
	char *buffer;

	if (av[0] == '.' || av[0] == '/')
	{
		if (access(av, X_OK) == 0)
			return (av);
	}

	while (pusher)
	{
		buffer = _strcat(pusher->dir, "/", av);
		if (access(buffer, X_OK) == 0)
		{
			return (buffer);
		}
		free(buffer);
		pusher = pusher->next;
	}
	return (NULL);
}
