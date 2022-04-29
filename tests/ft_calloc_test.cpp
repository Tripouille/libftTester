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

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv);
	title("ft_calloc\t: ")

	void * p = ft_calloc(2, 2);
	void * p2 = ft_calloc(SIZE_MAX, SIZE_MAX);
	char e[] = {0, 0, 0, 0};
	/* 1 */ check(!memcmp(p, e, 4));
	/* 2 */ mcheck(p, 4); free(p);
	/* 3 */ check(p2 == NULL); free(p2); showLeaks();
	write(1, "\n", 1);
	return (0);
}
