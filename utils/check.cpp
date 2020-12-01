#include "check.hpp"

extern int iTest;

void check(bool succes)
{
	if (succes)
		cout << FG_GREEN << iTest++ << ".OK ";
	else
		cout << FG_RED << iTest++ << ".KO ";
}

void mcheck(void * p, size_t required_size)
{
	#ifdef __unix__
	void * p2 = malloc(required_size); 
	if (malloc_usable_size(p) == malloc_usable_size(p2))
		cout << FG_GREEN << iTest++ << ".MOK ";
	else
		cout << FG_RED << iTest++ << ".MKO ";
	free(p2);
	#endif
	#ifdef __APPLE__
	void * p2 = malloc(required_size); 
	if (malloc_size(p) == malloc_size(p2))
		cout << FG_GREEN << iTest++ << ".MOK ";
	else
		cout << FG_RED << iTest++ << ".MKO ";
	free(p2);
	#endif
}