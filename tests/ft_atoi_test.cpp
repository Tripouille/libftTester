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

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv); 
	cout << FG_LGRAY << "ft_atoi\t\t: ";

	char escape[] = {9, 10, 11, 12, 13, 0};
	string e(escape);
	/* 1 */ check(ft_atoi((e + "1").c_str()) == 1);
	/* 2 */ check(ft_atoi((e + "a1").c_str()) == 0);
	/* 3 */ check(ft_atoi((e + "--1").c_str()) == 0);
	/* 4 */ check(ft_atoi((e + "++1").c_str()) == 0);
	/* 5 */ check(ft_atoi((e + "+1").c_str()) == 1);
	/* 6 */ check(ft_atoi((e + "-1").c_str()) == -1);
	/* 7 */ check(ft_atoi((e + "0").c_str()) == 0);
	/* 8 */ check(ft_atoi((e + "+42lyon").c_str()) == 42);
	/* 9 */ check(ft_atoi((e + "+101").c_str()) == 101);
	/* 10 */ check(ft_atoi((e + to_string(INT_MAX)).c_str()) == INT_MAX);
	/* 11 */ check(ft_atoi((e + to_string(INT_MIN)).c_str()) == INT_MIN);
	/* 12 */ check(ft_atoi("-+42") == 0);
	/* 13 */ check(ft_atoi("+-42") == 0);
	/* 14 */ check(ft_atoi((string("+") + e + "42").c_str()) == 0);
	/* 15 */ check(ft_atoi((string("-") + e + "42").c_str()) == 0);
	/* 16 */ check(ft_atoi((string("1") + e + "42").c_str()) == 1);
	/* 17 */ check(ft_atoi((string("-1") + e + "42").c_str()) == -1);
	cout << ENDL;
	return (0);
}