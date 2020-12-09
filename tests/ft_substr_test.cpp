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
	cout << FG_LGRAY << "ft_substr\t: ";

	char * s = ft_substr("tripouille", 0, 42000);
	/* 1 */ check(!strcmp(s, "tripouille"));
	/* 2 */ mcheck(s, strlen("tripouille") + 1); free(s);

	s = ft_substr("tripouille", 1, 1);
	/* 3 */ check(!strcmp(s, "r"));
	/* 4 */ mcheck(s, 2); free(s);

	s = ft_substr("tripouille", 100, 1);
	/* 5 */ check(!strcmp(s, ""));
	/* 6 */ mcheck(s, 1); free(s);

	char * str = strdup("1");
	s = ft_substr(str, 42, 42000000);
	/* 7 */ check(!strcmp(s, ""));
	/* 8 */ mcheck(s, 1); free(s); free(str);
	cout << ENDL;
	return (0);
}