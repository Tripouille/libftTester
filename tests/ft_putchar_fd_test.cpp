extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_putchar_fd\t: ";

	int fd = open("tripouille", O_RDWR | O_CREAT);
	ft_putchar_fd('a', fd);
	lseek(fd, SEEK_SET, 0);
	char s[10] = {0}; read(fd, s, 2);
	/* 1 */ check(!strcmp(s, "a"));
	unlink("./tripouille");
	cout << ENDL;
	return (0);
}