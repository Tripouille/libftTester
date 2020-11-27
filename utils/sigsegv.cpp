#include "sigsegv.hpp"
#include "color.hpp"

void sigsegv(int signal)
{
	(void)signal;
	cout << FG_LYELLOW << "SIGSEGV" << ENDL;
	exit(-1);
}
