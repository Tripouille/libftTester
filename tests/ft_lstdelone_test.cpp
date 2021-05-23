extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "leaks.hpp"
#include <string.h>

void freeList(t_list *head) {if (head) freeList(head->next); free(head);}
void delContent(void *ptr) {if (ptr) *(char *)ptr = 0;}

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv); (void)iTest;
	title("ft_lstdelone\t: ");

	char *content;
	content = (char *)malloc(1);
	*content = 42;
	t_list * l =  ft_lstnew(content);
	ft_lstdelone(l, delContent);
	check(*content == 0); showLeaks();
	free(content);
	write(1, "\n", 1);
	return (0);
}
