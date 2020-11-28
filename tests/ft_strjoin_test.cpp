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
	cout << FG_LGRAY << "ft_strjoin\t: ";

	char * s = ft_strjoin("tripouille", "42");
	check(!strcmp(s, "tripouille42"));
	void * s2 = malloc(strlen("tripouille") + strlen("42") + 1);
	check(malloc_usable_size(s) == malloc_usable_size(s2)); free(s); free(s2);

	s = ft_strjoin("", "42");
	check(!strcmp(s, "42"));
	s2 = malloc(strlen("") + strlen("42") + 1);
	check(malloc_usable_size(s) == malloc_usable_size(s2)); free(s); free(s2);

	s = ft_strjoin("42", "");
	check(!strcmp(s, "42"));
	s2 = malloc(strlen("42") + strlen("") + 1);
	check(malloc_usable_size(s) == malloc_usable_size(s2)); free(s); free(s2);

	s = ft_strjoin("", "");
	check(!strcmp(s, ""));
	s2 = malloc(strlen("") + strlen("") + 1);
	check(malloc_usable_size(s) == malloc_usable_size(s2)); free(s); free(s2);
	cout << ENDL;
	return (0);
}