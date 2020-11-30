extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include <string.h>

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_strlcpy\t: ";
	
	char src[] = "coucou";
	char dest[10]; memset(dest, 'A', 10);
	/* 1 */ check(ft_strlcpy(dest, src, 0) == strlen(src) && dest[0] == 'A');
	/* 2 */ check(ft_strlcpy(dest, src, 1) == strlen(src) && dest[0] == 0 && dest[1] == 'A');
	/* 3 */ check(ft_strlcpy(dest, src, 2) == strlen(src) && dest[0] == 'c' && dest[1] == 0);
	/* 4 */ check(ft_strlcpy(dest, src, -1) == strlen(src) && !strcmp(src, dest) && dest[strlen(src) + 1] == 'A');
	cout << ENDL;
	return (0);
}