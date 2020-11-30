extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include <string.h>

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_calloc\t: ";

	void * p = ft_calloc(2, 2);
	char e[] = {0, 0, 0, 0};
	/* 1 */ check(!memcmp(p, e, 4));
	/* 2 */ mcheck(p, 4); free(p);
	cout << ENDL;
	return (0);
}