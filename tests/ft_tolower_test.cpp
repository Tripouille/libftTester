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
	cout << FG_LGRAY << "ft_tolower\t: ";
	
	check(ft_tolower('A' - 1) == 'A' - 1);
	check(ft_tolower('A') == 'a');
	check(ft_tolower('Z' + 1) == 'Z' + 1);
	check(ft_tolower('Z') == 'z');
	cout << ENDL;
	return (0);
}