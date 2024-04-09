#include "simple.h"

/**
 * _getchar - obtain each char of the command line
 * Return: cmd line or EOF.
 **/

int _getchar(void)
{
	static unsigned char buff[BUFF_SIZE];
	static int counts;
	static int indeX;

	indeX = 0;
	counts = 0;

	if (indeX >= counts)
	{
		indeX = 0;
		counts = read(STDIN_FILENO, buff, BUFF_SIZE);
		printf("%i\n", counts);
		if (counts == 0)
			return (EOF);
		if (counts < 0)
			return (EOF);
	}
	return (buff[indeX++]);
}
