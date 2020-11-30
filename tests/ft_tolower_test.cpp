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
	cout << FG_LGRAY << "ft_tolower\t: ";
	
	/* 1 */ check(ft_tolower('A' - 1) == 'A' - 1);
	/* 2 */ check(ft_tolower('A') == 'a');
	/* 3 */ check(ft_tolower('Z' + 1) == 'Z' + 1);
	/* 4 */ check(ft_tolower('Z') == 'z');
	cout << ENDL;
	return (0);
}