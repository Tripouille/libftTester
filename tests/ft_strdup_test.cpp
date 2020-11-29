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
	cout << FG_LGRAY << "ft_strdup\t: ";

	char * s = ft_strdup((char*)"coucou");
	check(!strcmp(s, "coucou"));
	mcheck(s, strlen("coucou") + 1); free(s);
	
	s = ft_strdup((char*)"");
	check(!strcmp(s, ""));
	mcheck(s, 1); free(s);
	cout << ENDL;
	return (0);
}