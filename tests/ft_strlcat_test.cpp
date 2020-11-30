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
	cout << FG_LGRAY << "ft_strlcat\t: ";
	
	char dest[30]; memset(dest, 0, 30);
	char src[10]; memset(src, 'A', 9); src[9] = 0;
	dest[0] = 'B';
	/* 1 */ check(ft_strlcat(dest, src, 0) == strlen(src) && dest[0] == 'B');
	dest[0] = 'B';
	/* 2 */ check(ft_strlcat(dest, src, 1) == 10 && dest[0] == 'B' && dest[1] == 0);
	memset(dest, 'B', 4);
	/* 3 */ check(ft_strlcat(dest, src, 3) == 3 + strlen(src) && dest[3] == 'B' && dest[4] == 0);
	/* 4 */ check(ft_strlcat(dest, src, 6) == 13 && !memcmp(dest, "BBBBA", 6));
	memset(dest, 'C', 5);
	/* 5 */ check(ft_strlcat(dest, src, -1) == 14 && !memcmp(dest, "CCCCCAAAAAAAAA", 15));
	cout << ENDL;
	return (0);
}