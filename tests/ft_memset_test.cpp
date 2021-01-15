extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include <unistd.h>
#include "sigsegv.hpp"
#include "check.hpp"
#include <string.h>
#include "leak.hpp"


int iTest = 1;
int main(void)
{
	/*signal(SIGSEGV, sigsegv);  
	cout << FG_LGRAY << "ft_memset\t: ";
	
	char tab[100];
	memset(tab, 0, 100);
	ft_memset(tab, 'A', 0);*/
	/* 1 */ //check(tab[0] == 0);
	/*ft_memset(tab, 'A', 42);
	int i = 0;
	for (; i < 100 && tab[i] == 'A'; ++i)
		;*/
	/* 2 */ //check(i == 42 && tab[42] == 0)
	write(1, "test\n", 5);
	//showLeaks();
	//cout << ENDL;
	return (0);
}