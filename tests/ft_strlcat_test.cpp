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
	char * src = (char *)"AAAAAAAAA";
	dest[0] = 'B';
	/* 1 */ check(ft_strlcat(dest, src, 0) == strlen(src) && !strcmp(dest, "B"));
	dest[0] = 'B';
	/* 2 */ check(ft_strlcat(dest, src, 1) == 10 && !strcmp(dest, "B"));
	memset(dest, 'B', 4);
	/* 3 */ check(ft_strlcat(dest, src, 3) == 3 + strlen(src) && !strcmp(dest, "BBBB"));
	/* 4 */ check(ft_strlcat(dest, src, 6) == 13 && !strcmp(dest, "BBBBA"));
	memset(dest, 'C', 5);
	/* 5 */ check(ft_strlcat(dest, src, -1) == 14 && !strcmp(dest, "CCCCCAAAAAAAAA"));
	memset(dest, 'C', 15);
	/* 6 */ check(ft_strlcat(dest, src, 17) == 24 && !strcmp(dest, "CCCCCCCCCCCCCCCA"));
	memset(dest, 0, 30);
	/* 7 */ check(ft_strlcat(dest, src, 1) == strlen(src) && !strcmp(dest, ""));
	memset(dest, 0, 30); memset(dest, '1', 10);
	/* 8 */ check(ft_strlcat(dest, src, 5) == strlen(src) + 5 && !strcmp(dest, "1111111111"));
	memset(dest, 0, 30); memset(dest, '1', 10);
	/* 9 */ check(ft_strlcat(dest, src, 5) == strlen(src) + 5 && !strcmp(dest, "1111111111"));
	memset(dest, 0, 30); memset(dest, '1', 10);
	/* 10 */ check(ft_strlcat(dest, "", 15) == 10 && !strcmp(dest, "1111111111"));
	memset(dest, 0, 30);
	/* 11 */ check(ft_strlcat(dest, "", 42) == 0 && !strcmp(dest, ""));
	memset(dest, 0, 30);
	/* 12 */ check(ft_strlcat(dest, "", 0) == 0 && !strcmp(dest, ""));
	memset(dest, 0, 30);
	/* 13 */ check(ft_strlcat(dest, "123", 1) == 3 && !strcmp(dest, ""));
	memset(dest, 0, 30);
	/* 14 */ check(ft_strlcat(dest, "123", 2) == 3 && !strcmp(dest, "1"));
	memset(dest, 0, 30);
	/* 15 */ check(ft_strlcat(dest, "123", 3) == 3 && !strcmp(dest, "12"));
	memset(dest, 0, 30);
	/* 16 */ check(ft_strlcat(dest, "123", 4) == 3 && !strcmp(dest, "123"));
	memset(dest, 0, 30);
	/* 17 */ check(ft_strlcat(dest, "123", 0) == 3 && !strcmp(dest, ""));
	cout << ENDL;
	return (0);
}