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
	cout << FG_LGRAY << "ft_memset\t: ";
	char tab[100];
	memset(tab, 0, 100);
	ft_memset(tab, 'A', 0);
	if (tab[0] != 0)
		return(ko());
	ft_memset(tab, 'A', 42);
	int i = 0;
	for (; i < 100 && tab[i] == 'A'; ++i);
	if (i != 42 || tab[42] != 0)
		return(ko());
	return (ok());
}