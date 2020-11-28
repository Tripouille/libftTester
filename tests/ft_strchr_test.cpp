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
	cout << FG_LGRAY << "ft_strchr\t: ";
	char s[] = "tripouille";
	check(ft_strchr(s, 't') == s);
	check(ft_strchr(s, 'l') == s + 7);
	check(ft_strchr(s, 'z') == 0);
	check(ft_strchr(s, 0) == s + strlen(s));
	cout << ENDL;
	return (0);
}