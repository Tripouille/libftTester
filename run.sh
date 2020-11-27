clang++ -I.. -I utils/ tests/ft_strlen_test.cpp utils/sigsegv.cpp utils/color.cpp -L.. -lft  && ./a.out
rm a.out