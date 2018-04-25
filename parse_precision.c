#include "ft_printf.h"

t_DATA *parse_precision(t_DATA *DATA)
{
  while (DATA->f_treat[DATA->i] == '.')
  {
    DATA->i++;
	DATA->precision = 0;
  }
  while (DATA->f_treat[DATA->i] >= '0' && DATA->f_treat[DATA->i] <= '9')
  {
    DATA->precision *= 10;
    DATA->precision += (DATA->f_treat[DATA->i] - 48);
    DATA->i++;
  }
  return (DATA);
}
