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
	cout << FG_LGRAY << "ft_strncmp\t: ";
	
	char s[] = "tripouille";
	char sCpy[] = "tripouille";
	char s2[] = "trifouille";
	check(ft_strncmp(s, s2, 0) == 0);
	check(ft_strncmp(s, s2, 3) == 0);
	check(ft_strncmp(s, s2, 4) == 'p' - 'f');
	check(ft_strncmp(s, sCpy, -1) == 0);
	cout << ENDL;
	return (0);
}