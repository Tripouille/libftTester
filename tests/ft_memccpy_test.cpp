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
	cout << FG_LGRAY << "ft_memccpy\t: ";
	
	char dest[100];
	memset(dest, 'A', 100);
	/* 1 */ check(ft_memccpy(dest, "coucou", 0, 0) == 0 && dest[0] == 'A');
	/* 2 */ check(ft_memccpy(dest, "coucou", 0, 1) == 0 && dest[0] == 'c' && dest[1] == 'A');
	dest[0] = 'A';
	/* 3 */ check(ft_memccpy(dest, "coucou", 'c', 10) == dest + 1 && dest[0] == 'c' && dest[1] == 'A');
	dest[0] = 'A';
	/* 4 */ check(ft_memccpy(dest, "B", 0, 10) == dest + 2 && dest[0] == 'B' && dest[1] == 0);
	char src[10];
	memset(src, 0, 10);
	/* 5 */ check(ft_memccpy(dest, src, 'A', 10) == NULL);
	int i = 0;
	for (; i < 100 && dest[i] == 0; ++i)
		;
	/* 6 */ check(i == 10);
	cout << ENDL;
	return (0);
}