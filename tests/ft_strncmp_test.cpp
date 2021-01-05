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
	cout << FG_LGRAY << "ft_strncmp\t: ";
	
	/* 1 */ check(ft_strncmp("t", "", 0) == 0);
	/* 2 */ check(ft_strncmp("1234", "1235", 3) == 0);
	/* 3 */ check(ft_strncmp("1234", "1235", 4) < 0);
	/* 4 */ check(ft_strncmp("1234", "1235", -1) < 0);
	/* 5 */ check(ft_strncmp("", "", 42) == 0);
	/* 6 */ check(ft_strncmp("Tripouille", "Tripouille", 42) == 0);
	/* 7 */ check(ft_strncmp("Tripouille", "tripouille", 42) < 0);
	/* 8 */ check(ft_strncmp("Tripouille", "TriPouille", 42) > 0);
	/* 9 */ check(ft_strncmp("Tripouille", "TripouillE", 42) > 0);
	/* 10 */ check(ft_strncmp("Tripouille", "TripouilleX", 42) < 0);
	/* 11 */ check(ft_strncmp("Tripouille", "Tripouill", 42) > 0);
	/* 12 */ check(ft_strncmp("", "1", 0) == 0);
	/* 13 */ check(ft_strncmp("1", "", 0) == 0);
	/* 14 */ check(ft_strncmp("", "1", 1) < 0);
	/* 15 */ check(ft_strncmp("1", "", 1) > 0);
	/* 16 */ check(ft_strncmp("", "", 1) == 0);
	cout << ENDL;
	return (0);
}