extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include <string.h>
#include <malloc.h>

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_strjoin\t: ";

	char * s = ft_strjoin("tripouille", "42");
	check(!strcmp(s, "tripouille42"));
	mcheck(s, strlen("tripouille") + strlen("42") + 1); free(s);

	s = ft_strjoin("", "42");
	check(!strcmp(s, "42"));
	mcheck(s, strlen("") + strlen("42") + 1); free(s);

	s = ft_strjoin("42", "");
	check(!strcmp(s, "42"));
	mcheck(s, strlen("42") + strlen("") + 1); free(s);

	s = ft_strjoin("", "");
	check(!strcmp(s, ""));
	mcheck(s, strlen("") + strlen("") + 1); free(s);
	cout << ENDL;
	return (0);
}