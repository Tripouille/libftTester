#ifndef LEAK_HPP
# define LEAK_HPP
# include <stdlib.h>

typedef struct s_mlist
{
	void * p;
	size_t size;
	struct s_mlist * prev;
	struct s_mlist * next;
}				t_mlist;

extern t_mlist * mallocList;

void * my_malloc(size_t size);
void my_free(void * p);

void init_hook(void);
void mallocListAdd(void * p, size_t size);
void mallocListRemove(void * p);
void showLeaks(void);

#endif