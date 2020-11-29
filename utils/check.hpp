#ifndef CHECK_HPP
# define CHECK_HPP
# include <iostream>
# include <string>
# include <malloc.h>
# include "color.hpp"

using namespace std;

void check(bool succes);
void mcheck(void * p, size_t required_size);

#endif