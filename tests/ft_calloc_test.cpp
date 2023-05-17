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
#include <limits.h>

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv);
	title("ft_calloc\t: ")

	void * p = ft_calloc(2, 2);
	char e[] = {0, 0, 0, 0};
	/* 1 */ check(!memcmp(p, e, 4));
	/* 2 */ mcheck(p, 4); free(p); showLeaks();
	/* 3 */ check(ft_calloc(SIZE_MAX, SIZE_MAX) == NULL);

	/* @evportel */
	/* 4 */ check(ft_calloc(INT_MAX, INT_MAX) == NULL);
	p = ft_calloc(INT_MIN, INT_MIN);
	/* 5 */ check(p == NULL); free(p); //showLeaks();
	p = ft_calloc(0, 0);
	/* 6 */ check(p != NULL); free(p); //showLeaks();
	p = ft_calloc(0, 5);
	/* 7 */ check(p != NULL); free(p); //showLeaks();
	p = ft_calloc(5, 0);
	/* 8 */ check(p != NULL); free(p); //showLeaks();
	p = ft_calloc(-5, -5);
	/* 9 */ check(p == NULL); free(p); //showLeaks();
	p = ft_calloc(0, -5);
	/* 10 */ check(p != NULL); free(p); //showLeaks();
	p = ft_calloc(-5, 0);
	/* 11 */ check(p != NULL); free(p); //showLeaks();
	p = ft_calloc(3, -5);
	/* 12 */ check(p == NULL); free(p); //showLeaks();
	p = ft_calloc(-5, 3);
	/* 13 */ check(p == NULL); free(p); //showLeaks();

	write(1, "\n", 1);
	return (0);
}