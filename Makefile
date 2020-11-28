.DEFAULT_GOAL	:= m
UTILS			= utils/sigsegv.cpp utils/color.cpp
TESTS_PATH		= tests/
MANDATORY		= memset bzero memcpy memccpy memmove memchr memcmp strlen isalpha isdigit isalnum \
				isascii isprint toupper tolower strchr strrchr strncmp strlcpy strlcat strnstr \
				atoi calloc strdup substr strjoin strtrim split itoa strmapi putchar_fd putstr_fd \
				putendl_fd putnbr_fd	
VMANDATORY		= $(addprefix v, $(MANDATORY))
BONUS			= lstnew lstadd_front lstsize lstlast lstadd_back lstdelone lstclear lstiter lstmap
VBONUS			= $(addprefix v, $(BONUS))
VSOPEN			= $(addprefix vs, $(MANDATORY)) $(addprefix vs, $(BONUS))

CC		= clang++
CFLAGS	= -g3 -std=c++11 -I utils/ -I.. -lbsd

$(MANDATORY): %: mandatory_start
	@$(CC) $(CFLAGS) $(UTILS) $(TESTS_PATH)ft_$*_test.cpp -L.. -lft && ./a.out && rm -f a.out

$(VMANDATORY): v%: mandatory_start
	@$(CC) $(CFLAGS) $(UTILS) $(TESTS_PATH)ft_$*_test.cpp -L.. -lft && valgrind -q --leak-check=full ./a.out && rm -f a.out

$(BONUS): %: bonus_start
	@$(CC) $(CFLAGS) $(UTILS) $(TESTS_PATH)ft_$*_test.cpp -L.. -lft && ./a.out && rm -f a.out

$(VBONUS): v%: bonus_start
	@$(CC) $(CFLAGS) $(UTILS) $(TESTS_PATH)ft_$*_test.cpp -L.. -lft && valgrind -q --leak-check=full ./a.out && rm -f a.out

$(VSOPEN): vs%: v%
	@code $(TESTS_PATH)ft_$*_test.cpp

mandatory_start:
	make -C ..
	@tput setaf 4 && echo [Mandatory]

bonus_start:
	make bonus -C ..
	@tput setaf 5 && echo [Bonus]

m: $(MANDATORY)
b: $(BONUS)
a: m b
vm: $(VMANDATORY)
vb: $(VBONUS)
va: vm vb

clean:
	make clean -C ..	

.PHONY:	mandatory_start m vm bonus_start b vb a va clean