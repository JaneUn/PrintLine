#include "get_next_line.h"

int main(int ac, char **av)
{
	int fd;
	int ret;
	int line;
	char *buff;
	line = 0;
	ret = 0;
	buff = NULL;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while ((ret = get_next_line(fd, &buff)) > 0)
		{
			printf("Return value: %d | Line #%d: %s\n", ret, ++line, buff);
			free(buff);
		}
		printf("Return value: %d | Line #%d: %s\n", ret, ++line, buff);
		if (buff)
			free(buff);
		if (ret == -1)
			printf("-----------\nError\n");
		else if (ret == 0)
			printf("-----------\nEnd of file\n");
	}
	else
		printf("Error\n");
	if (close(fd) != 0)
		printf("Cannot close file\n");
	else
		close(fd);
	return (0);
}
