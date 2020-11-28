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
	cout << FG_LGRAY << "ft_isdigit\t: ";

	check(!ft_isdigit('0' - 1));
	check(ft_isdigit('0'));
	check(!ft_isdigit('9' + 1));
	check(ft_isdigit('9'));
	cout << ENDL;
	return (0);
}