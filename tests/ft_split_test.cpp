extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include <string.h>

void freeTab(char * * tab)
{
	for (int i = 0; tab[i] != NULL; ++i)
		free(tab[i]);
	free(tab);
}

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_split\t: ";

	char * * tab = ft_split("  tripouille  42  ", ' ');
	mcheck(tab, sizeof(char *) * 3);

	check(!strcmp(tab[0], "tripouille"));
	mcheck(tab[0], strlen("tripouille") + 1);

	check(!strcmp(tab[1], "42"));
	mcheck(tab[1], strlen("42") + 1);

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