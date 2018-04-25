#include "ft_printf.h"

t_DATA *parse_field_width(t_DATA *DATA)
{
   while (DATA->f_treat[DATA->i] >= '0' && DATA->f_treat[DATA->i] <= '9')
    {
      DATA->field_width *= 10;
      DATA->field_width += (DATA->f_treat[DATA->i] - 48);
      DATA->i++;
    }
  return(DATA);
}
