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
	cout << FG_LGRAY << "ft_toupper\t: ";
	
	check(ft_toupper('a' - 1) == 'a' - 1);
	check(ft_toupper('a') == 'A');
	check(ft_toupper('z' + 1) == 'z' + 1);
	check(ft_toupper('z') == 'Z');
	cout << ENDL;
	return (0);
}