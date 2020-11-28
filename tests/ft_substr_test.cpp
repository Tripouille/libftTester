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
	cout << FG_LGRAY << "ft_substr\t: ";

	char * s = ft_substr("tripouille", 0, -1);
	check(!strcmp(s, "tripouille"));
	void * s2 = malloc(strlen("tripouille") + 1);
	check(malloc_usable_size(s) == malloc_usable_size(s2)); free(s); free(s2);

	s = ft_substr("tripouille", 1, 1);
	check(!strcmp(s, "r"));
	s2 = malloc(2);
	check(malloc_usable_size(s) == malloc_usable_size(s2)); free(s); free(s2);

	s = ft_substr("tripouille", 100, 1);
	check(!strcmp(s, ""));
	s2 = malloc(1);
	check(malloc_usable_size(s) == malloc_usable_size(s2)); free(s); free(s2);
	cout << ENDL;
	return (0);
}