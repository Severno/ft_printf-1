#include <stdarg.h>
#include <stdio.h>


void	func(int count, ...)
{
	va_list		list;
	printf("%d\n", va_start(list, count));
	printf("%d Count %d\n", va_arg(list, int), count);
	printf("%d Count %d\n", va_arg(list, int), count);
	printf("%d Count %d\n", va_arg(list, int), count);
	printf("%d Count %d\n", va_arg(list, int), count);
}

int		main(void)
{
	func(7, 3, 5, 2, 9, 1);
	return (0);
}
