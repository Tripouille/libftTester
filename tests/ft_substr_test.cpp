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
	cout << FG_LGRAY << "ft_substr\t: ";

	char * s = ft_substr("tripouille", 0, 42000);
	check(!strcmp(s, "tripouille"));
	mcheck(s, strlen("tripouille") + 1); free(s);

	s = ft_substr("tripouille", 1, 1);
	check(!strcmp(s, "r"));
	mcheck(s, 2); free(s);

	s = ft_substr("tripouille", 100, 1);
	check(!strcmp(s, ""));
	mcheck(s, 1); free(s);
	cout << ENDL;
	return (0);
}