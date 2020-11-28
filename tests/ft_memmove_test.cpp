extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include <string.h>

int ko(void) {cout << FG_RED << "KO" << ENDL; return (0);}
int ok(void) {cout << FG_GREEN << "OK" << ENDL; return (0);}

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_memmove\t: ";
	char s[] = {65, 66, 67, 68, 69, 0, 45};
	char s0[] = { 0,  0,  0,  0,  0,  0, 0};
	char sCpy[] = {65, 66, 67, 68, 69, 0, 45};
	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	char sResult2[] = {67, 67, 68, 68, 69, 0, 45};

	if (ft_memmove(s0, s, 7) != s0 
	|| memcmp(s, s0, 7)) //Post 0
		return (ko());
	if (ft_memmove(s, s + 2, 0) != s
	|| memcmp(s, sCpy, 7)) //0 move
		return (ko());
	if (ft_memmove(s, s + 2, 2) != s
	|| memcmp(s, sResult, 7)) //forward
		return (ko());
	if (ft_memmove(s + 1, s, 2) != s + 1
	|| memcmp(s, sResult2, 7)) //reverse
		return (ko());
	return (ok());
}