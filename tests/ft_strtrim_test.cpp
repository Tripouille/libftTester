extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include <string.h>
#include <malloc.h>

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_strtrim\t: ";

	char * s = ft_strtrim("   xxxtripouille", " x");
	check(!strcmp(s, "tripouille"));
	mcheck(s, strlen("tripouille") + 1); free(s);

	s = ft_strtrim("tripouille   xxx", " x");
	check(!strcmp(s, "tripouille"));
	mcheck(s, strlen("tripouille") + 1); free(s);

	s = ft_strtrim("   xxxtripouille   xxx", " x");
	check(!strcmp(s, "tripouille"));
	mcheck(s, strlen("tripouille") + 1); free(s);
	
	s = ft_strtrim("   xxx   xxx", " x");
	check(!strcmp(s, ""));
	mcheck(s, 1); free(s);
	cout << ENDL;
	return (0);
}