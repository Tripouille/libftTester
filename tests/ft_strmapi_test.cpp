extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include <string.h>
#include <malloc.h>
#include <climits>

void check(bool succes) {if (succes) cout << FG_GREEN << "OK "; else cout << FG_RED << "KO ";}

char addOne(unsigned int i, char c) {return (i + c);}

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_strmapi\t: ";

	char * s = ft_strmapi("1234", addOne);
	check(!strcmp(s, "1357"));
	void * p = malloc(strlen("1357") + 1);
	check(malloc_usable_size(s) == malloc_usable_size(p)); free(s); free(p);

	s = ft_strmapi("", addOne);
	check(!strcmp(s, ""));
	p = malloc(strlen("") + 1);
	check(malloc_usable_size(s) == malloc_usable_size(p)); free(s); free(p);
	cout << ENDL;
	return (0);
}