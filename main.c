#include "ft_printf.h"
#include <limits.h>

int		main(void)
{
	
	int		val;
	unsigned int	p;

	p = 4294967295;

	val = ft_printf("%");
									printf("[%d]\n\n", val);
	val =    printf("%");
									printf("[%d]\n\n", val);

/*
	char str[] = "yoyoyoyoyo";
	int val;

	val = ft_printf("Hello %10.0s\n", str);
									printf("[%d]\n\n", val);
	val =    printf("Hello %10.0s\n", str);
									printf("[%d]\n\n", val);
	return (0);
	*/
}
