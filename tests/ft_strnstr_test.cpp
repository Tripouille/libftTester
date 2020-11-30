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
	cout << FG_LGRAY << "ft_strnstr\t: ";

	char haystack[30] = "aaabc";
	char needle[10] = "aabc";
	char empty[] = "";
	/* 1 */ check(ft_strnstr(haystack, needle, 0) == 0);
	/* 2 */ check(ft_strnstr(haystack, needle, -1) == haystack + 1);
	/* 3 */ check(ft_strnstr(haystack, "a", -1) == haystack);
	/* 4 */ check(ft_strnstr(haystack, "c", -1) == haystack + strlen(haystack) - 1);
	/* 5 */ check(ft_strnstr(empty, "", -1) == empty);
	/* 6 */ check(ft_strnstr(empty, "", 0) == empty);
	/* 7 */ check(ft_strnstr(empty, "coucou", -1) == 0);
	cout << ENDL;
	return (0);
}