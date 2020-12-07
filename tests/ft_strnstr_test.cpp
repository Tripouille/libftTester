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

	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	char * empty = (char *)malloc(1); empty[0] = 0;
	/* 1 */ check(ft_strnstr(haystack, needle, 0) == 0);
	/* 2 */ check(ft_strnstr(haystack, needle, -1) == haystack + 1);
	/* 3 */ check(ft_strnstr(haystack, "a", -1) == haystack);
	/* 4 */ check(ft_strnstr(haystack, "c", -1) == haystack + 4);
	/* 5 */ check(ft_strnstr(empty, "", -1) == empty);
	/* 6 */ check(ft_strnstr(empty, "", 0) == empty);
	/* 7 */ check(ft_strnstr(empty, "coucou", -1) == 0);
	/* 8 */ check(ft_strnstr(haystack, "aaabc", 5) == haystack);
	/* 9 */ check(ft_strnstr(empty, "12345", 5) == 0); free(empty);
	/* 10 */ check(ft_strnstr(haystack, "abcd", 9) == haystack + 5);
	/* 11 */ check(ft_strnstr(haystack, "cd", 8) == NULL);
	cout << ENDL;
	return (0);
}