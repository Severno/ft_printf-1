clear
make
gcc main.c libftprintf.a -I includes -I srcs/libft/includes
./a.out | cat -e
