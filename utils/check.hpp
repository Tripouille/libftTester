#ifndef CHECK_HPP
# define CHECK_HPP
# include <iostream>
# include <string>
# include "color.hpp"

# ifdef __unix__
#  include <malloc.h>
# endif
# ifdef __APPLE__
#  include <stdlib.h>
#  include <malloc/malloc.h>
# endif

using namespace std;

void check(bool succes);
void mcheck(void * p, size_t required_size);

#endif