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
	cout << FG_LGRAY << "ft_isalpha\t: ";

	check(!ft_isalpha('a' - 1));
	check(ft_isalpha('a'));
	check(!ft_isalpha('z' + 1));
	check(ft_isalpha('z'));
	check(!ft_isalpha('A' - 1));
	check(ft_isalpha('A'));
	check(!ft_isalpha('Z' + 1));
	check(ft_isalpha('Z'));
	cout << ENDL;
	return (0);
}