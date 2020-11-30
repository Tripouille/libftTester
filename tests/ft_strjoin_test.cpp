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
	cout << FG_LGRAY << "ft_strjoin\t: ";

	char * s = ft_strjoin("tripouille", "42");
	/* 1 */ check(!strcmp(s, "tripouille42"));
	/* 2 */ mcheck(s, strlen("tripouille") + strlen("42") + 1); free(s);

	s = ft_strjoin("", "42");
	/* 3 */ check(!strcmp(s, "42"));
	/* 4 */ mcheck(s, strlen("") + strlen("42") + 1); free(s);

	s = ft_strjoin("42", "");
	/* 5 */ check(!strcmp(s, "42"));
	/* 6 */ mcheck(s, strlen("42") + strlen("") + 1); free(s);

	s = ft_strjoin("", "");
	/* 7 */ check(!strcmp(s, ""));
	/* 8 */ mcheck(s, strlen("") + strlen("") + 1); free(s);
	cout << ENDL;
	return (0);
}