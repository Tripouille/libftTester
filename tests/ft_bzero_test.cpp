extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include <string.h>

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_bzero\t: ";
	
	char tab[100];
	memset(tab, 'A', 100);
	ft_bzero(tab, 0);
	check(tab[0] == 'A');
	ft_bzero(tab, 42);
	int i = 0;
	for (; i < 100 && tab[i] == 0; ++i);
	check(i == 42 && tab[42] == 'A');
	cout << ENDL;
	return (0);
}