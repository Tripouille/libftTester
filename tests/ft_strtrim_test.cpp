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
	cout << FG_LGRAY << "ft_strtrim\t: ";

	char * s = ft_strtrim("   xxxtripouille", " x");
	/* 1 */ check(!strcmp(s, "tripouille"));
	/* 2 */ mcheck(s, strlen("tripouille") + 1); free(s);

	s = ft_strtrim("tripouille   xxx", " x");
	/* 3 */ check(!strcmp(s, "tripouille"));
	/* 4 */ mcheck(s, strlen("tripouille") + 1); free(s);

	s = ft_strtrim("   xxxtripouille   xxx", " x");
	/* 5 */ check(!strcmp(s, "tripouille"));
	/* 6 */ mcheck(s, strlen("tripouille") + 1); free(s);
	
	s = ft_strtrim("   xxx   xxx", " x");
	/* 7 */ check(!strcmp(s, ""));
	/* 8 */ mcheck(s, 1); free(s);
	cout << ENDL;
	return (0);
}