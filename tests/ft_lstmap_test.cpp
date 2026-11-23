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

void freeList(t_list *head) {if (head) freeList((t_list *)head->next); free(head);}
void * addOne(void * p) {void * r = malloc(sizeof(int)); *(int*)r = *(int*)p + 1; return (r);}

static void * addOneOrNull(void *p) {return p ? addOne(p) : NULL;}

static void checkNullContent(int nullIndex)
{
	int values[] = {10, 20, 30};
	t_list input[] = {{values, NULL}, {values + 1, NULL}, {values + 2, NULL}};
	input[0].next = &input[1];
	input[1].next = &input[2];
	input[nullIndex].content = NULL;
	t_list *mapped = ft_lstmap(input, addOneOrNull, free);
	t_list *node = mapped;
	bool ok = true;

	for (int i = 0; i < 3 && ok; ++i)
	{
		ok = node && (i == nullIndex ? node->content == NULL
			: node->content && *(int *)node->content == values[i] + 1);
		if (ok)
			node = node->next;
	}
	check(ok && node == NULL);
	ft_lstclear(&mapped, free); showLeaks();
}

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv);
	title("ft_lstmap\t: ")

	int tab[] = {0, 1, 2, 3};
	t_list * l =  ft_lstnew(tab);
	for (int i = 1; i < 4; ++i)
		ft_lstadd_back(&l, ft_lstnew(tab + i));
	t_list * m = ft_lstmap(l, addOne, free);
	t_list * tmp = l;
	/* 1 2 3 4 */ for (int i = 0; i < 4; ++i)
	{
		check(*(int*)tmp->content == i);
		tmp = (t_list *)tmp->next;
	}
	tmp = m;
	/* 5 6 7 8 */ for (int i = 0; i < 4; ++i)
	{
		check(*(int*)tmp->content == i + 1);
		tmp = (t_list *)tmp->next;
	}
	freeList(l); ft_lstclear(&m, free); showLeaks();
	/* 9 10 11 */ for (int i = 0; i < 3; ++i)
		checkNullContent(i);
	write(1, "\n", 1);
	return (0);
}
