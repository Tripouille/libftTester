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
	cout << FG_LGRAY << "ft_bzero\t: ";
	char tab[100];
	memset(tab, 'A', 100);
	ft_bzero(tab, 0);
	if (tab[0] != 'A')
		return (ko());
	ft_bzero(tab, 42);
	int i = 0;
	for (; i < 100 && tab[i] == 0; ++i);
	if (i != 42 || tab[42] != 'A')
		return (ko());
	return (ok());
}