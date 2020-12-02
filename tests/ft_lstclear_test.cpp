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
	cout << FG_LGRAY << "ft_lstclear\t: ";

	t_list * l =  ft_lstnew(malloc(1));
	for (int i = 0; i < 10; ++i)
		ft_lstadd_front(&l, ft_lstnew(malloc(1)));
	ft_lstclear(&l, free);
	/* 1 */ check(l == 0);
	/* 2 All other checks are done by valgrind */
	cout << ENDL;
	return (0);
}