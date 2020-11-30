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
	cout << FG_LGRAY << "ft_strdup\t: ";

	char * s = ft_strdup((char*)"coucou");
	/* 1 */ check(!strcmp(s, "coucou"));
	/* 2 */ mcheck(s, strlen("coucou") + 1); free(s);
	
	s = ft_strdup((char*)"");
	/* 3 */ check(!strcmp(s, ""));
	/* 4 */ mcheck(s, 1); free(s);
	cout << ENDL;
	return (0);
}