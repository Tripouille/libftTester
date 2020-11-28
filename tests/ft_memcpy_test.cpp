extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include <string.h>

void check(bool succes) {if (succes) cout << FG_GREEN << "OK "; else cout << FG_RED << "KO ";}

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_memcpy\t: ";
	
	char dest[100];
	memset(dest, 'A', 100);
	ft_memcpy(dest, "coucou", 0);
	check(dest[0] == 'A');
	char src[] = {0, 0};
	ft_memcpy(dest, src, 2);
	int i = 0;
	for (; i < 100 && dest[i] == 0; ++i);
	check (i == 2 && dest[2] == 'A');
	cout << ENDL;
	return (0);
}