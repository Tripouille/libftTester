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
	cout << FG_LGRAY << "ft_strrchr\t: ";
	char s[] = "tripouille";
	char s2[] = "ltripouiel";
	/* 1 */ check(ft_strrchr(s, 't') == s);
	/* 2 */ check(ft_strrchr(s, 'l') == s + 8);
	/* 3 */ check(ft_strrchr(s2, 'l') == s2 + 9);
	/* 4 */ check(ft_strrchr(s, 'z') == 0);
	/* 5 */ check(ft_strrchr(s, 0) == s + strlen(s));
	/* 6 */ check(ft_strrchr(s, 't' + 256) == s);
	cout << ENDL;
	return (0);
}