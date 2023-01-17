#include "get_next_line.h"
#include <fcntl.h>

int main (void)
{
	int fd;
	fd = open("/Users/lsaba-qu/42Cursus/01_get_next_line/test.txt", O_RDONLY, S_IRUSR | S_IWUSR);
	char *test;
	
	test = get_next_line(fd);
	printf("%s", test);
	return (0);
}