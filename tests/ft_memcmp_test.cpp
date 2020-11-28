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
	cout << FG_LGRAY << "ft_memcmp\t: ";

	char s[] = {-128, 0, 127, 0};
	char sCpy[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};
	check(!ft_memcmp(s, sCpy, 4));
	check(!ft_memcmp(s, s2, 0));
	check(ft_memcmp(s, s2, 1) > 0);
	check(ft_memcmp(s2, s, 1) < 0);
	check(ft_memcmp(s2, s3, 4) != 0);
	cout << ENDL;
	return (0);
}