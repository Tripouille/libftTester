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
	cout << FG_LGRAY << "ft_isascii\t: ";

	check(!ft_isascii(-1));
	check(ft_isascii(0));
	check(!ft_isascii(128));
	check(ft_isascii(127));
	cout << ENDL;
	return (0);
}