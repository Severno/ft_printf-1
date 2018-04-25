#include "ft_printf.h"

t_DATA *parse_converter(t_DATA *DATA)
{
  size_t i;

  i = 0;
  while(DATA->converter_mask[i] != '\0')
    {
      while(DATA->converter_mask[i] == DATA->f_treat[DATA->i])
      {
        while (DATA->f_treat[DATA->i] == '-')
        {
          DATA->converter_flag[0] = '-';
          DATA->i++;
        }
        while (DATA->f_treat[DATA->i] == '+')
        {
          DATA->converter_flag[1] = '+';
          DATA->i++;
        }
        while (DATA->f_treat[DATA->i] == ' ')
        {
          DATA->converter_flag[2] = ' ';
          DATA->i++;
        }
        while (DATA->f_treat[DATA->i] == '0')
        {
          DATA->converter_flag[3] = '0';
          DATA->i++;
        }
        while (DATA->f_treat[DATA->i] == '#')
        {
          DATA->converter_flag[4] = '#';
          DATA->i++;
        }
        i = 0;
      }
      i++;
    }
    return(DATA);
}
