# ft_printf
### Score 101/100
##### Mandatory
100/100
##### Bonus
01/25
***
### Challenge
**Note** *This project is no longer updated. ft_printf is now part of [libft](https://github.com/davhojt/libft "libft, a 42 project"), my personal C library. See [ft_printf](https://github.com/davhojt/libft/tree/master/srcs/ft_printf "ft_printf, inside libft") inside libft. In the [libft version](https://github.com/davhojt/libft/tree/master/srcs/ft_printf "ft_printf, inside libft") you can just use the function by including libft.a and ft_printf.a.*  
  
To recode libc's `printf`.  
  
At 42, students are not allowed to use library functions. We can only submit wholly recreated programs and functions.
ft_printf must be formatted in the same manor as libc's `printf`. For example:
```c
ft_printf("%s is a %d student\n", "Dav", 42);
printf("%s is a %d student\n", "Dav", 42);
```
Should give back:
```console
Dav is a 42 student
Dav is a 42 student
```
  
The project is complicated as there is an indefinate nnumber of parameters passed to the function. We use variadic arguments in this case.  
  
ft_printf must achieve the following mandatory requirements:  
  
* Manage the following conversions: `s`, `S`, `p`, `d`, `D`, `i`, `o`, `O`, `u`, `U`, `x`, `X`, `c` & `C`
* Manage `%%`
* Manage the flags `#`, `0`, `-`, `+` & `space`
* Manage the minimum field-width
* Manage the precision
* Manage the flags `hh`, `h`, `l`, `ll`, `j`, & `z`.
  
The function must conform to 42's norm.  
The function cannot leak. All errors must be handled carefully. In no way can the function quit in an unexpected manner (Segmentation fault, bus error, double free, etc).  
Allowed functions are `write`, `getloacale`, `malloc`, `free`, `exit` and the three functions of `stdarg`. Everything else is forbidden.

### Using the project
The project must be submitted without a Makefile. To compile first run:
```console
make -C libft/ fclean && make -C libft/
```
Then run:
```console
clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft
```

This will compile **test_gnl**. Execute with a fillit map as a parameter.
```console
./test_gnl [input_file]
```
