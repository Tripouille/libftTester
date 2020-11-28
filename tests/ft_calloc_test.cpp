extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include <string.h>

void check(bool succes) {if (succes) cout << FG_GREEN << "OK "; else cout << FG_RED << "KO ";}

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_calloc\t: ";

	void * p = ft_calloc(2, 2);
	char e[] = {0, 0, 0, 0};
	check(!memcmp(p, e, 4));
	cout << ENDL;
	return (0);
}