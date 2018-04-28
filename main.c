#include "ft_printf.h"
#include <limits.h>
#include <ctype.h>
#include <locale.h>

int		main(void)
{

	int				val;
	unsigned long			c;

	setlocale(LC_ALL, "");
		c = 0x1234;

	val = ft_printf("{%30S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("[%d]\n\n", val);
	val =    printf("{%30S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("[%d]\n\n", val);

	printf("\n\n\n\n");


	ft_printf("{%30S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("\n");
	printf("{%30S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");

	





	return (0);
}
