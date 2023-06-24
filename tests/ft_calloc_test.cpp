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
	/* 3 */ check(ft_calloc(SIZE_MAX, SIZE_MAX) == NULL); showLeaks();

	/* @evportel */
	/* The following tests are not supported by the function's documentation. 
 	* But some effects returned in the trait by Moulinette so the following 
  	* tests were implemented. */
	/* 4 */ check(ft_calloc(INT_MAX, INT_MAX) == NULL);
	/* 5 */ check(ft_calloc(INT_MIN, INT_MIN) == NULL); showLeaks();
	p = ft_calloc(0, 0);
	/* 6 */ check(p != NULL); free(p); showLeaks();
	p = ft_calloc(0, 5);
	/* 7 */ check(p != NULL); free(p); showLeaks();
	p = ft_calloc(5, 0);
	/* 8 */ check(p != NULL); free(p); showLeaks();
	/* 9 */ check(ft_calloc(-5, -5) == NULL); showLeaks();
	p = ft_calloc(0, -5);
	/* 10 */ check(p != NULL); free(p); showLeaks();
	p = ft_calloc(-5, 0);
	/* 11 */ check(p != NULL); free(p); showLeaks();
	/* 12 */ check(ft_calloc(3, -5) == NULL); showLeaks();
	/* 13 */ check(ft_calloc(-5, 3) == NULL); showLeaks();

	write(1, "\n", 1);
	return (0);
}
