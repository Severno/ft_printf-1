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

	val = ft_printf("%ls, %ls", L"ÊM-^ZM-^VÁM-^BM-^I", L"ŸM-^Dÿ≠ŸM-^E ÿÆŸM-^Fÿ≤ŸM-ÿ±");
	printf("[%d]\n\n", val);
	val =    printf("%ls, %ls", L"ÊM-^ZM-^VÁM-^BM-^I", L"ŸM-^Dÿ≠ŸM-^E ÿÆŸM-^Fÿ≤ŸM-ÿ±");
	printf("[%d]\n\n", val);

	printf("\n\n\n\n");

	val = ft_printf("%ls", L"ÊM-^ZM-^VÁM-^BM-^I");
	printf("[%d]\n\n", val);
	val =    printf("%ls", L"ÊM-^ZM-^VÁM-^BM-^I");
	printf("[%d]\n\n", val);

	val = ft_printf("coco et %-#-#--24X titi%#012x", 12, -874);
	printf("[%d]\n\n", val);
	val =    printf("coco et %-#-#--24X titi%#012x", 12, -874);
	printf("[%d]\n\n", val);

	printf("\n\n\n\n");


	return (0);
}
