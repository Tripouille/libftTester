.DEFAULT_GOAL	:= m
UTILS			= utils/sigsegv.cpp utils/color.cpp
TESTS_PATH		= tests/
MANDATORY		= memset bzero memcpy memccpy memmove memchr memcmp strlen isalpha isdigit isalnum \
				isascii isprint toupper tolower strchr strrchr strncmp strlcpy strlcat strnstr \
				atoi calloc strdup substr strjoin strtrim split itoa strmapi putchar_fd putstr_fd \
				putendl_fd putnbr_fd
BONUS			= lstnew lstadd_front lstsize lstlast lstadd_back lstdelone lstclear lstiter lstmap

CC		= clang++
CFLAGS	= -g3 -std=c++98 -I utils/ -I.. -lbsd

$(MANDATORY): %: mandatory_start
	@$(CC) $(CFLAGS) $(UTILS) $(TESTS_PATH)ft_$@_test.cpp -L.. -lft && ./a.out && rm -f a.out

$(BONUS): %: bonus_start
	@$(CC) $(CFLAGS) $(UTILS) $(TESTS_PATH)ft_$@_test.cpp -L.. -lft && ./a.out && rm -f a.out

mandatory_start:
	make -C ..
	@tput setaf 4 && echo [Mandatory]

bonus_start:
	make bonus -C ..
	@tput setaf 5 && echo [Bonus]

m: $(MANDATORY)
b: $(BONUS)
a: m b

.PHONY:	mandatory_start m bonus_start b a