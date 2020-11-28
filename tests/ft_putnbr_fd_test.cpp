extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <climits>

void check(bool succes) {if (succes) cout << FG_GREEN << "OK "; else cout << FG_RED << "KO ";}

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_putnbr_fd\t: ";

	int fd = open("tripouille", O_RDWR | O_CREAT);
	ft_putnbr_fd(0, fd);
	lseek(fd, SEEK_SET, 0);
	char s[42] = {0}; read(fd, s, 2);
	check(!strcmp(s, "0"));
	unlink("./tripouille");

	fd = open("tripouille", O_RDWR | O_CREAT);
	ft_putnbr_fd(10, fd);
	lseek(fd, SEEK_SET, 0);
	read(fd, s, 3);
	check(!strcmp(s, "10"));
	unlink("./tripouille");

	fd = open("tripouille", O_RDWR | O_CREAT);
	ft_putnbr_fd(INT_MAX, fd);
	lseek(fd, SEEK_SET, 0);
	read(fd, s, 11);
	check(!strcmp(s, to_string(INT_MAX).c_str()));
	unlink("./tripouille");

	fd = open("tripouille", O_RDWR | O_CREAT);
	ft_putnbr_fd(INT_MIN, fd);
	lseek(fd, SEEK_SET, 0);
	read(fd, s, 11);
	check(!strcmp(s, to_string(INT_MIN).c_str()));
	unlink("./tripouille");

	cout << ENDL;
	return (0);
}