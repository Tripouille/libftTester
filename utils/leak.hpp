#ifndef LEAK_HPP
# define LEAK_HPP
# include <stdlib.h>
# include <vector>

/*struct ptr
{
	void * p;
	size_t size;
};*/

/*extern std::vector<ptr> mallocList;*/

void * malloc(size_t size) throw();
void free(void * p) throw();

void mallocListAdd(void * p, size_t size);
void mallocListRemove(void * p);
void showLeaks(void);

#endif