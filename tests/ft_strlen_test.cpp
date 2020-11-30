extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_strlen\t: ";

	/* 1 */ check(ft_strlen("123") == 3);
	/* 2 */ check(ft_strlen("") == 0);
	cout << ENDL;
	return (0);
}