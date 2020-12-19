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
	
	char s[] = "tripouille";
	char sCpy[] = "tripouille";
	char s2[] = "trifouille";
	/* 1 */ check(ft_strncmp(s, s2, 0) == 0);
	/* 2 */ check(ft_strncmp(s, s2, 3) == 0);
	/* 3 */ check(ft_strncmp(s, s2, 4) == 'p' - 'f');
	/* 4 */ check(ft_strncmp(s, sCpy, -1) == 0);
	/* 5 */ check(ft_strncmp("", "", 42) == 0);
	/* 6 */ check(ft_strncmp("Tripouille", "Tripouille", 42) == 0);
	/* 7 */ check(ft_strncmp("Tripouille", "tripouille", 42) == 'T' - 't');
	/* 8 */ check(ft_strncmp("Tripouille", "TriPouille", 42) == 'p' - 'P');
	/* 9 */ check(ft_strncmp("Tripouille", "TripouillE", 42) == 'e' - 'E');
	/* 10 */ check(ft_strncmp("Tripouille", "TripouilleX", 42) == -'X');
	/* 11 */ check(ft_strncmp("Tripouille", "Tripouill", 42) == 'e');
	cout << ENDL;
	return (0);
}