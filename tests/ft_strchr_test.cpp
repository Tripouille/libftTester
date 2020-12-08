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
	cout << FG_LGRAY << "ft_strchr\t: ";
	char s[] = "tripouille";
	/* 1 */ check(ft_strchr(s, 't') == s);
	/* 2 */ check(ft_strchr(s, 'l') == s + 7);
	/* 3 */ check(ft_strchr(s, 'z') == 0);
	/* 4 */ check(ft_strchr(s, 0) == s + strlen(s));
	/* 5 */ check(ft_strchr(s, 't' + 256) == s);
	cout << ENDL;
	return (0);
}