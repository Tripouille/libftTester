make -C .. || exit
clang++ -I.. -I utils/ tests/ft_memset_test.cpp utils/sigsegv.cpp utils/color.cpp -L.. -lft  && valgrind -q --leak-check=full ./a.out
clang++ -I.. -I utils/ tests/ft_bzero_test.cpp utils/sigsegv.cpp utils/color.cpp -L.. -lft  && valgrind -q --leak-check=full ./a.out
clang++ -I.. -I utils/ tests/ft_memcpy_test.cpp utils/sigsegv.cpp utils/color.cpp -L.. -lft  && valgrind -q --leak-check=full ./a.out
clang++ -I.. -I utils/ tests/ft_strlen_test.cpp utils/sigsegv.cpp utils/color.cpp -L.. -lft  && valgrind -q --leak-check=full ./a.out
rm a.out