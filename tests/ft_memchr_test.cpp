extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include <string.h>

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_memchr\t: ";
	
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	check(ft_memchr(s, 0, 0) == NULL);
	check(ft_memchr(s, 0, 1) == s);
	check(ft_memchr(s, 2, 3) == s + 2);
	check(ft_memchr(s, 6, 6) == NULL);
	cout << ENDL;
	return (0);
}