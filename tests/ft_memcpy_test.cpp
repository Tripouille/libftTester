extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include<string.h>

int ko(void) {cout << FG_RED << "KO" << ENDL; return (0);}
int ok(void) {cout << FG_GREEN << "OK" << ENDL; return (0);}

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_memcpy\t: ";
	char dest[100];
	memset(dest, 'A', 100);
	ft_memcpy(dest, "coucou", 0);
	if (dest[0] != 'A')
		return (ko());
	ft_memcpy(dest, "BBBBBB", 1);
	int i = 0;
	for (; i < 100 && dest[i] == 'B'; ++i);
	if (i != 1 || dest[1] != 'A')
		return (ko());
	return (ok());
}