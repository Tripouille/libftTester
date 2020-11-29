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
	cout << FG_LGRAY << "ft_strnstr\t: ";

	char haystack[30] = "aaabc";
	char needle[10] = "aabc";
	char empty[] = "";
	check(ft_strnstr(haystack, needle, 0) == 0);
	check(ft_strnstr(haystack, needle, -1) == haystack + 1);
	check(ft_strnstr(haystack, "a", -1) == haystack);
	check(ft_strnstr(haystack, "c", -1) == haystack + strlen(haystack) - 1);
	check(ft_strnstr(empty, "", -1) == empty);
	check(ft_strnstr(empty, "", 0) == empty);
	check(ft_strnstr(empty, "coucou", -1) == 0);
	cout << ENDL;
	return (0);
}