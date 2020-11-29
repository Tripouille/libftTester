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

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_lstdelone\t: " << FG_LYELLOW << BOLD << "CHECK WITH VALGRIND ";

	t_list * l =  ft_lstnew(malloc(1));
	ft_lstdelone(l, free);
	cout << ENDL;
	return (0);
}