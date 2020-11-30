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
	cout << FG_LGRAY << "ft_isprint\t: ";

	/* 1 */ check(!ft_isprint(' ' - 1));
	/* 2 */ check(ft_isprint(' '));
	/* 3 */ check(!ft_isprint('~' + 1));
	/* 4 */ check(ft_isprint('~'));
	cout << ENDL;
	return (0);
}