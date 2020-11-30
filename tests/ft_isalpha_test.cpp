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
	cout << FG_LGRAY << "ft_isalpha\t: ";

	/* 1 */ check(!ft_isalpha('a' - 1));
	/* 2 */ check(ft_isalpha('a'));
	/* 3 */ check(!ft_isalpha('z' + 1));
	/* 4 */ check(ft_isalpha('z'));
	/* 5 */ check(!ft_isalpha('A' - 1));
	/* 6 */ check(ft_isalpha('A'));
	/* 7 */ check(!ft_isalpha('Z' + 1));
	/* 8 */ check(ft_isalpha('Z'));
	cout << ENDL;
	return (0);
}