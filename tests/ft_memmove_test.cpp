extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include <string.h>

void check(bool succes) {if (succes) cout << FG_GREEN << "OK "; else cout << FG_RED << "KO ";}

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_memmove\t: ";
	
	char s[] = {65, 66, 67, 68, 69, 0, 45};
	char s0[] = { 0,  0,  0,  0,  0,  0, 0};
	char sCpy[] = {65, 66, 67, 68, 69, 0, 45};
	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	char sResult2[] = {67, 67, 68, 68, 69, 0, 45};

	check(ft_memmove(s0, s, 7) == s0 && !memcmp(s, s0, 7)); //Post 0
	check(ft_memmove(s, s + 2, 0) && !memcmp(s, sCpy, 7)); //0 move
	check(ft_memmove(s, s + 2, 2) == s && !memcmp(s, sResult, 7)); //forward
	check(ft_memmove(sResult + 1, sResult, 2) == sResult + 1 && !memcmp(sResult, sResult2, 7)); //reverse
	cout << ENDL;
	return (0);
}