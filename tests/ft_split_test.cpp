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

void freeTab(char * * tab)
{
	for (int i = 0; tab[i] != NULL; ++i)
		free(tab[i]);
	free(tab);
}

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_split\t\t: ";

	char * * tab = ft_split("  tripouille  42  ", ' ');
	void *  p = malloc(sizeof(char *) * 3);
	check(malloc_usable_size(tab) == malloc_usable_size(p)); free(p);

	check(!strcmp(tab[0], "tripouille"));
	p = malloc(strlen("tripouille") + 1);
	check(malloc_usable_size(tab[0]) == malloc_usable_size(p)); free(p);

	check(!strcmp(tab[1], "42"));
	p = malloc(strlen("42") + 1);
	check(malloc_usable_size(tab[1]) == malloc_usable_size(p)); free(p);

	check(tab[2] == NULL);
	freeTab(tab);

	tab = ft_split("tripouille", 0);
	check(!strcmp(tab[0], "tripouille"));
	check(tab[1] == NULL);
	freeTab(tab);

	tab = ft_split("     ", ' ');
	check(tab[0] == NULL);
	free(tab);
	cout << ENDL;
	return (0);
}