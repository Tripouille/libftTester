.DEFAULT_GOAL := mandatory
UTILS = utils/sigsegv.cpp utils/color.cpp
TESTS_PATH = tests/
MANDATORY = memset bzero memcpy memccpy strlen
BONUS = prout

CC		= clang++
CFLAGS	= -g3 -Wall -Wextra -Werror -Wconversion -std=c++98 -I utils/ -I..

$(MANDATORY): %:
	@$(CC) $(CFLAGS) $(UTILS) $(TESTS_PATH)ft_$@_test.cpp -L.. -lft && ./a.out

$(BONUS): %:
	@$(CC) $(CFLAGS) $(UTILS) $(TESTS_PATH)ft_$@_test.cpp -L.. -lft && ./a.out

mandatory_start:
	make -C ..
	@tput setaf 4 && echo [Mandatory]

bonus_start:
	make bonus -C ..
	@tput setaf 4 && echo [Bonus]

mandatory: mandatory_start $(MANDATORY) clean
bonus: bonus_start $(BONUS) clean
all: mandatory bonus

clean:
	@rm -f a.out

.PHONY:	all clean fclean re color