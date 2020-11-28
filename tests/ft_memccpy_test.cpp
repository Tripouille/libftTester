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
	cout << FG_LGRAY << "ft_memccpy\t: ";
	char dest[100];
	memset(dest, 'A', 100);
	if (ft_memccpy(dest, "coucou", 0, 0) != 0 || dest[0] != 'A')
		return (ko());
	if (ft_memccpy(dest, "coucou", 0, 1) != 0 || dest[0] != 'c' || dest[1] != 'A')
		return (ko());
	dest[0] = 'A';
	if (ft_memccpy(dest, "coucou", 'c', 10) != dest + 1 || dest[0] != 'c' || dest[1] != 'A')
		return (ko());
	dest[0] = 'A';
	if (ft_memccpy(dest, "B", 0, 10) != dest + 2 || dest[0] != 'B' || dest[1] != 0)
		return (ko());
	char src[10];
	memset(src, 0, 10);
	if (ft_memccpy(dest, src, 'A', 10) != NULL)
		return (ko());
	int i = 0;
	for (; i < 100 && dest[i] == 0; ++i);
	if (i != 10)
		return (ko());
	return (ok());
}