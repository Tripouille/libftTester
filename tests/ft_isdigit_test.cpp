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
	cout << FG_LGRAY << "ft_isdigit\t: ";

	check(!ft_isdigit('0' - 1));
	check(ft_isdigit('0'));
	check(!ft_isdigit('9' + 1));
	check(ft_isdigit('9'));
	cout << ENDL;
	return (0);
}