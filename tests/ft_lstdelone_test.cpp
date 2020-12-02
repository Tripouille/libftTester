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
	signal(SIGSEGV, sigsegv); (void)iTest;
	cout << FG_LGRAY << "ft_lstdelone\t: " << FG_GREEN << "0";

	t_list * l =  ft_lstnew(malloc(1));
	ft_lstdelone(l, free);
	/* 0 All checks are done by valgrind */ 
	cout << ENDL;
	return (0);
}