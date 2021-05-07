extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "leaks.hpp"
#include <string.h>

void freeTab(char * * tab)
{
	for (int i = 0; tab[i] != NULL; ++i)
		free(tab[i]);
	free(tab);
}

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv);
	title("ft_split\t: ")

	char * * tab = ft_split("  tripouille  42  ", ' ');
	/* 1 */ mcheck(tab, sizeof(char *) * 3);

	/* 2 */ check(!strcmp(tab[0], "tripouille"));
	/* 3 */ mcheck(tab[0], strlen("tripouille") + 1);

	/* 4 */ check(!strcmp(tab[1], "42"));
	/* 5 */ mcheck(tab[1], strlen("42") + 1);

	/* 6 */ check(tab[2] == NULL);
	freeTab(tab); showLeaks();

	tab = ft_split("tripouille", 0);
	/* 7 */ check(!strcmp(tab[0], "tripouille"));
	/* 8 */ check(tab[1] == NULL);
	freeTab(tab); showLeaks();

	tab = ft_split("     ", ' ');
	/* 9 */ check(tab[0] == NULL);
	free(tab); showLeaks();

	char * invalidReadCheck = new char; *invalidReadCheck = 0;
	tab = ft_split(invalidReadCheck, 0);
	/* 10 */ check(tab[0] == NULL); delete invalidReadCheck;
	free(tab); showLeaks();

	tab = ft_split("chinimala", ' ');
	/* 11 */ mcheck(tab, sizeof(char *) * 2);
	/* 12 */ check(!strcmp(tab[0], "chinimala"));
	/* 13 */ check(tab[1] == NULL);
	freeTab(tab); showLeaks();

	tab = ft_split("", ' ');
	/* 14 */ mcheck(tab, sizeof(char *) * 1);
	/* 15 */ check(tab[0] == NULL);
	freeTab(tab); showLeaks();

	/* sguerra- */
	char * splitme = strdup("Tripouille");
	tab = ft_split(splitme, ' ');
	/* 16 */ mcheck(tab, sizeof(char *) * 2);
	/* 17 */ check(!strcmp(tab[0], "Tripouille"));
	/* 18 */ check(tab[1] == NULL);
	free(splitme); freeTab(tab); showLeaks();

	splitme = strdup("Tripouille ");
	tab = ft_split(splitme, ' ');
	/* 19 */ mcheck(tab, sizeof(char *) * 2);
	/* 20 */ check(!strcmp(tab[0], "Tripouille"));
	/* 21 */ check(tab[1] == NULL);
	free(splitme); freeTab(tab); showLeaks();

	splitme = strdup(" Tripouille");
	tab = ft_split(splitme, ' ');
	/* 22 */ mcheck(tab, sizeof(char *) * 2);
	/* 23 */ check(!strcmp(tab[0], "Tripouille"));
	/* 24 */ check(tab[1] == NULL);
	free(splitme); freeTab(tab); showLeaks();

	splitme = strdup(" Tripouille ");
	tab = ft_split(splitme, ' ');
	/* 25 */ mcheck(tab, sizeof(char *) * 2);
	/* 26 */ check(!strcmp(tab[0], "Tripouille"));
	/* 27 */ mcheck(tab[0], strlen("Tripouille") + 1);
	/* 28 */ check(tab[1] == NULL);
	free(splitme); freeTab(tab); showLeaks();

	write(1, "\n", 1);
	return (0);
}