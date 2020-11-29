extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include <string.h>
#include <climits>

char addOne(unsigned int i, char c) {return (i + c);}

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_strmapi\t: ";

	char * s = ft_strmapi("1234", addOne);
	check(!strcmp(s, "1357"));
	mcheck(s, strlen("1357") + 1); free(s);

	s = ft_strmapi("", addOne);
	check(!strcmp(s, ""));
	mcheck(s, strlen("") + 1); free(s);
	cout << ENDL;
	return (0);
}