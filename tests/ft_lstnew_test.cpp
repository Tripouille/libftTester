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

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_lstnew\t: ";

	t_list * l =  ft_lstnew((void*)42);
	check(l->content == (void*)42);
	check(l->next == 0);
	void * p = malloc(sizeof(t_list));
	check(malloc_usable_size(l) == malloc_usable_size(p)); free(l); free(p);
	cout << ENDL;
	return (0);
}