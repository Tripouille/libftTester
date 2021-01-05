#ifndef LEAK_HPP
#define LEAK_HPP

#include <stdlib.h>

typedef struct s_mlist
{
	void * p;
	size_t size;
	struct s_mlist * prev;
	struct s_mlist * next;
}				t_mlist;

extern t_mlist * mallocList;

extern void __real_free(void * p);
void __wrap_free(void * p);

extern void * __real_malloc(size_t size);
void * __wrap_malloc(size_t size);

void mallocListAdd(void * p, size_t size);
void mallocListRemove(void * p);
void showLeaks(void);

#endif