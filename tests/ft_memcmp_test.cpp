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
	cout << FG_LGRAY << "ft_memcmp\t: ";

	char s[] = {-128, 0, 127, 0};
	char sCpy[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};
	/* 1 */ check(!ft_memcmp(s, sCpy, 4));
	/* 2 */ check(!ft_memcmp(s, s2, 0));
	/* 3 */ check(ft_memcmp(s, s2, 1) > 0);
	/* 4 */ check(ft_memcmp(s2, s, 1) < 0);
	/* 5 */ check(ft_memcmp(s2, s3, 4) != 0);
	cout << ENDL;
	return (0);
}