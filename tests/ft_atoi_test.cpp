extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include <string.h>
#include <climits>

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_atoi\t\t: ";

	char escape[] = {9, 10, 11, 12, 13, 0};
	string e(escape);
	check(ft_atoi((e + "1").c_str()) == 1);
	check(ft_atoi((e + "a1").c_str()) == 0);
	check(ft_atoi((e + "--1").c_str()) == 0);
	check(ft_atoi((e + "++1").c_str()) == 0);
	check(ft_atoi((e + "+1").c_str()) == 1);
	check(ft_atoi((e + "-1").c_str()) == -1);
	check(ft_atoi((e + "0").c_str()) == 0);
	check(ft_atoi((e + "+42lyon").c_str()) == 42);
	check(ft_atoi((e + "+101").c_str()) == 101);
	check(ft_atoi((e + to_string(INT_MAX)).c_str()) == INT_MAX);
	check(ft_atoi((e + to_string(INT_MIN)).c_str()) == INT_MIN);
	cout << ENDL;
	return (0);
}