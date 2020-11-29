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

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_itoa\t\t: ";

	char * s = ft_itoa(INT_MAX);
	check(!strcmp(s, to_string(INT_MAX).c_str()));
	mcheck(s, strlen(to_string(INT_MAX).c_str())); free(s);

	s = ft_itoa(INT_MIN);
	check(!strcmp(s, to_string(INT_MIN).c_str()));
	mcheck(s, strlen(to_string(INT_MIN).c_str())); free(s);

	s = ft_itoa(0);
	check(!strcmp(s, to_string(0).c_str()));
	mcheck(s, strlen(to_string(0).c_str())); free(s);

	s = ft_itoa(42);
	check(!strcmp(s, to_string(42).c_str()));
	mcheck(s, strlen(to_string(42).c_str())); free(s);
	cout << ENDL;
	return (0);
}