extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include <string.h>

void freeList(t_list *head) {if (head) freeList(head->next); free(head);}

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_lstsize\t: ";

	t_list * l =  NULL;
	/* 1 */ check(ft_lstsize(l) == 0);
	ft_lstadd_front(&l, ft_lstnew((void*)1));
	/* 2 */ check(ft_lstsize(l) == 1);
	ft_lstadd_front(&l, ft_lstnew((void*)2));
	/* 3 */ check(ft_lstsize(l) == 2);
	freeList(l);
	cout << ENDL;
	return (0);
}