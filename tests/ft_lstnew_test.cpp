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
	cout << FG_LGRAY << "ft_lstnew\t: ";

	t_list * l =  ft_lstnew((void*)42);
	/* 1 */ check(l->content == (void*)42);
	/* 2 */ check(l->next == 0);
	/* 3 */ mcheck(l, sizeof(t_list)); free(l);
	cout << ENDL;
	return (0);
}