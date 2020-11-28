extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include <string.h>

int ko(void) {cout << FG_RED << "KO" << ENDL; return (0);}
int ok(void) {cout << FG_GREEN << "OK" << ENDL; return (0);}

int main(void)
{
	signal(SIGSEGV, sigsegv);
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	cout << FG_LGRAY << "ft_memchr\t: ";
	if (ft_memchr(s, 0, 0) != NULL)
		return (ko());
	if (ft_memchr(s, 0, 1) != s)
		return (ko());
	if (ft_memchr(s, 2, 3) != s + 2)
		return (ko());
	if (ft_memchr(s, 6, 6) != NULL)
		return (ko());
	return (ok());
}