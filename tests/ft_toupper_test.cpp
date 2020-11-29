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
	cout << FG_LGRAY << "ft_toupper\t: ";
	
	check(ft_toupper('a' - 1) == 'a' - 1);
	check(ft_toupper('a') == 'A');
	check(ft_toupper('z' + 1) == 'z' + 1);
	check(ft_toupper('z') == 'Z');
	cout << ENDL;
	return (0);
}