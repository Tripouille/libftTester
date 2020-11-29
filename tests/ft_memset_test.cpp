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
	cout << FG_LGRAY << "ft_memset\t: ";
	
	char tab[100];
	memset(tab, 0, 100);
	ft_memset(tab, 'A', 0);
	check(tab[0] == 0);
	ft_memset(tab, 'A', 42);
	int i = 0;
	for (; i < 100 && tab[i] == 'A'; ++i);
	check(i == 42 && tab[42] == 0);
	cout << ENDL;
	return (0);
}