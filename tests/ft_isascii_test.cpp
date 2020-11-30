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
	cout << FG_LGRAY << "ft_isascii\t: ";

	/* 1 */ check(!ft_isascii(-1));
	/* 2 */ check(ft_isascii(0));
	/* 3 */ check(!ft_isascii(128));
	/* 4 */ check(ft_isascii(127));
	cout << ENDL;
	return (0);
}