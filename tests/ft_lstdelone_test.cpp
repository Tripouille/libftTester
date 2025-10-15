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
#include <stdlib.h>
static int del_called = 0;
void dummy_del(void *p) { free(p); del_called = 1; }
int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv); (void)iTest;
	title("ft_lstdelone\t: ");
	t_list *l = ft_lstnew(malloc(4));
	ft_lstdelone(l, dummy_del);
	/* 1 */check(del_called == 1);
	t_list *l2 = ft_lstnew(NULL);
	ft_lstdelone(l2, free);
	/* 2 */check(1);

	t_list *l3 = ft_lstnew(ft_strdup("first"));
	t_list *mid = ft_lstnew(ft_strdup("middle"));
	t_list *last = ft_lstnew(ft_strdup("last"));
	l3->next = mid;
	mid->next = last;
	ft_lstdelone(mid, free);

	/* 3 */check(ft_strncmp((char *)l3->content, "first", 5) == 0);
	/* 4 */check(ft_strncmp((char *)last->content, "last", 4) == 0);
	
	free(l3->content); free(last->content); free(last); free(l3); showLeaks();
	write(1, "\n", 1);
	return (0);
} 
