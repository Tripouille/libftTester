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
	cout << FG_LGRAY << "ft_strrchr\t: ";
	char s[] = "tripouille";
	char s2[] = "ltripouiel";
	check(ft_strrchr(s, 't') == s);
	check(ft_strrchr(s, 'l') == s + 8);
	check(ft_strrchr(s2, 'l') == s2 + 9);
	check(ft_strrchr(s, 'z') == 0);
	check(ft_strrchr(s, 0) == s + strlen(s));
	cout << ENDL;
	return (0);
}