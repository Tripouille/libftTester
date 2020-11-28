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

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_itoa\t: ";

	char * s = ft_itoa(INT_MAX);
	check(!strcmp(s, to_string(INT_MAX).c_str()));
	void * p = malloc(strlen(to_string(INT_MAX).c_str()));
	check(malloc_usable_size(s) == malloc_usable_size(p)); free(s); free(p);

	s = ft_itoa(INT_MIN);
	check(!strcmp(s, to_string(INT_MIN).c_str()));
	p = malloc(strlen(to_string(INT_MIN).c_str()));
	check(malloc_usable_size(s) == malloc_usable_size(p)); free(s); free(p);

	s = ft_itoa(0);
	check(!strcmp(s, to_string(0).c_str()));
	p = malloc(strlen(to_string(0).c_str()));
	check(malloc_usable_size(s) == malloc_usable_size(p)); free(s); free(p);

	s = ft_itoa(42);
	check(!strcmp(s, to_string(42).c_str()));
	p = malloc(strlen(to_string(42).c_str()));
	check(malloc_usable_size(s) == malloc_usable_size(p)); free(s); free(p);
	cout << ENDL;
	return (0);
}