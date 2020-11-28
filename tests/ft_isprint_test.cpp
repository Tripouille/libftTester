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
	cout << FG_LGRAY << "ft_isprint\t: ";

	check(!ft_isprint(' ' - 1));
	check(ft_isprint(' '));
	check(!ft_isprint('~' + 1));
	check(ft_isprint('~'));
	cout << ENDL;
	return (0);
}