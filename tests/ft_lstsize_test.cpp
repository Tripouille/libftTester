extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include <string.h>
#include <malloc.h>

void check(bool succes) {if (succes) cout << FG_GREEN << "OK "; else cout << FG_RED << "KO ";}

void freeList(t_list *head) {if (head) freeList(head->next); free(head);}

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_lstsize\t: ";

	t_list * l =  NULL;
	check(ft_lstsize(l) == 0);
	ft_lstadd_front(&l, ft_lstnew((void*)1));
	check(ft_lstsize(l) == 1);
	ft_lstadd_front(&l, ft_lstnew((void*)2));
	check(ft_lstsize(l) == 2);
	freeList(l);
	cout << ENDL;
	return (0);
}