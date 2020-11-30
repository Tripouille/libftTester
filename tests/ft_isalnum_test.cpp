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
	cout << FG_LGRAY << "ft_isalnum\t: ";

	/* 1 */ check(!ft_isalnum('a' - 1));
	/* 2 */ check(ft_isalnum('a'));
	/* 3 */ check(!ft_isalnum('z' + 1));
	/* 4 */ check(ft_isalnum('z'));
	/* 5 */ check(!ft_isalnum('A' - 1));
	/* 6 */ check(ft_isalnum('A'));
	/* 7 */ check(!ft_isalnum('Z' + 1));
	/* 8 */ check(ft_isalnum('Z'));
	/* 9 */ check(!ft_isalnum('0' - 1));
	/* 10 */ check(ft_isalnum('0'));
	/* 11 */ check(!ft_isalnum('9' + 1));
	/* 12 */ check(ft_isalnum('9'));
	cout << ENDL;
	return (0);
}