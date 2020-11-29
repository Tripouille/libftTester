extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include <string.h>
#include <malloc.h>

void check(bool succes) {if (succes) cout << FG_GREEN << "OK "; else cout << FG_RED << "KO ";}

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_strdup\t: ";

	char * s = ft_strdup((char*)"coucou");
	check(!strcmp(s, "coucou"));
	char * s2 = strdup("coucou");
	check(malloc_usable_size(s) == malloc_usable_size(s2)); free(s); free(s2);
	s = ft_strdup((char*)"");
	s2 = strdup("");
	check(!strcmp(s, ""));
	check(malloc_usable_size(s) == malloc_usable_size(s2)); free(s); free(s2);
	cout << ENDL;
	return (0);
}