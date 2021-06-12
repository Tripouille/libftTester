extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "leaks.hpp"
#include <string.h>

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv);
	title("ft_strrchr\t: ")
	char s[] = "tripouille";
	char s2[] = "ltripouiel";
	char s3[] = "taxtripouille";

	/* 1 */ check(ft_strrchr(s, 't') == s); showLeaks();
	/* 2 */ check(ft_strrchr(s, 'l') == s + 8); showLeaks();
	/* 3 */ check(ft_strrchr(s2, 'l') == s2 + 9); showLeaks();
	/* 4 */ check(ft_strrchr(s, 'z') == NULL); showLeaks();
	/* 5 */ check(ft_strrchr(s, 0) == s + strlen(s)); showLeaks();
	/* 6 */ check(ft_strrchr(s, 't' + 256) == s); showLeaks();
	/* 7 */ check(ft_strrchr(s3, 'x') == s3 + 3); showLeaks();
	char * empty = (char*)calloc(1, 1);
	/* 8 aperez-b */ check(ft_strrchr(empty, 'V') == NULL); free(empty); showLeaks();
	write(1, "\n", 1);
	return (0);
}
