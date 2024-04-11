#include "simple.h"

/**
 * _getchar - get each char of the command line
 * Return: cmd line or EOF.
 **/

int _getchar(void)
{
	static unsigned char buff[BUFF_SIZE];
	static int cnt;
	static int index;

	index = 0;
	cnt = 0;

	if (index >= cnt)
	{
		index = 0;
		cnt = read(STDIN_FILENO, buff, BUFF_SIZE);
		printf("%i\n", cnt);
		if (cnt == 0)
			return (EOF);
		if (cnt < 0)
			return (EOF);
	}
	return (buff[index++]);
}
