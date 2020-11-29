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
	cout << FG_LGRAY << "ft_isalnum\t: ";
	
	check(!ft_isalnum('a' - 1));
	check(ft_isalnum('a'));
	check(!ft_isalnum('z' + 1));
	check(ft_isalnum('z'));
	check(!ft_isalnum('A' - 1));
	check(ft_isalnum('A'));
	check(!ft_isalnum('Z' + 1));
	check(ft_isalnum('Z'));
	check(!ft_isalnum('0' - 1));
	check(ft_isalnum('0'));
	check(!ft_isalnum('9' + 1));
	check(ft_isalnum('9'));
	cout << ENDL;
	return (0);
}