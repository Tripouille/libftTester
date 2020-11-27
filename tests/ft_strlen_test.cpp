extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"

int ko(void) {cout << FG_RED << "KO" << ENDL; return (0);}
int ok(void) {cout << FG_GREEN << "OK" << ENDL; return (0);}

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_strlen\t: ";
	if (ft_strlen("123") != 3 || ft_strlen("") != 0)
		return (ko());
	return (ok());
}