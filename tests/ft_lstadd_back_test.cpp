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
	cout << FG_LGRAY << "ft_lstadd_back\t: ";

	t_list * l =  NULL;
	ft_lstadd_back(&l, ft_lstnew((void*)1));
	check(l->content == (void*)1);
	check(l->next == 0);

	ft_lstadd_back(&l, ft_lstnew((void*)2));
	check(l->content == (void*)1);
	check(l->next->content == (void*)2);
	check(l->next->next == 0);
	freeList(l);
	cout << ENDL;
	return (0);
}