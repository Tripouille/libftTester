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
	cout << FG_LGRAY << "ft_strtrim\t: ";

	char * s = ft_strtrim("   xxxtripouille", " x");
	check(!strcmp(s, "tripouille"));
	void * s2 = malloc(strlen("tripouille") + 1);
	check(malloc_usable_size(s) == malloc_usable_size(s2)); free(s); free(s2);

	s = ft_strtrim("tripouille   xxx", " x");
	check(!strcmp(s, "tripouille"));
	s2 = malloc(strlen("tripouille") + 1);
	check(malloc_usable_size(s) == malloc_usable_size(s2)); free(s); free(s2);

	s = ft_strtrim("   xxxtripouille   xxx", " x");
	check(!strcmp(s, "tripouille"));
	s2 = malloc(strlen("tripouille") + 1);
	check(malloc_usable_size(s) == malloc_usable_size(s2)); free(s); free(s2);
	
	s = ft_strtrim("   xxx   xxx", " x");
	check(!strcmp(s, ""));
	s2 = malloc(1);
	check(malloc_usable_size(s) == malloc_usable_size(s2)); free(s); free(s2);
	cout << ENDL;
	return (0);
}