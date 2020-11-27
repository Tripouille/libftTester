extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include<string.h>

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_memset : ";
	char tab[100];
	memset(tab, 0, 100);
	ft_memset(tab, 'A', 42);
	int i = 0;
	for (; i < 100 && tab[i] == 'A'; ++i);
	if (i != 42 || tab[42] != 0)
		cout << FG_RED << "KO";
	else
		cout << FG_GREEN << "OK";
	cout << ENDL;
	return (0);
}