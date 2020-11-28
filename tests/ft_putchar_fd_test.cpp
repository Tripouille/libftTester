extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void check(bool succes) {if (succes) cout << FG_GREEN << "OK "; else cout << FG_RED << "KO ";}

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_putchar_fd\t: ";

	int fd = open("tripouille", O_RDWR | O_CREAT);
	ft_putchar_fd('a', fd);
	lseek(fd, SEEK_SET, 0);
	char c; read(fd, &c, 1);
	check(c == 'a');
	unlink("./tripouille");
	cout << ENDL;
	return (0);
}