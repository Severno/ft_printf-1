/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 23:44:21 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/18 21:01:40 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		get_tens(int n)
{
	int tens;

	tens = 1;
	while ((n /= 10) > 0)
		tens++;
	return (tens);
}

static char		get_plus_minus_placeholder(t_DATA *DATA, int n)
{
	char	*tmp;

	tmp = DATA->converter_flag;

	if (n < 0)
		return ('-');
	if (tmp[1] == '+')
		return ('+');
	if (tmp[2] == ' ')
		return (' ');
	return ('\0');
}

t_DATA			*print_d(t_DATA *DATA, int nb, int num_width, int minus_flag)
{
	int			not_blank;
	char		plus_minus_placeholder;

	plus_minus_placeholder = get_plus_minus_placeholder(DATA, nb);

	if (num_width <= DATA->precision)
		not_blank = DATA->precision;
	else
		not_blank = num_width;
	if (plus_minus_placeholder)
		not_blank++;
	if (!minus_flag)
	{
		while (DATA->field_width-- > not_blank)
			write (1, " ", 1);
	}
	if (plus_minus_placeholder)
		write (1, &plus_minus_placeholder, 1);
	while (DATA->precision-- > num_width)
		write(1, "0", 1);
	ft_putnbr(nb);	
	if (minus_flag)
	{
		while (DATA->field_width-- > not_blank)
			write (1, " ", 1);
	}
	return (DATA);
}

t_DATA			*display_d(t_DATA *DATA)
{
	char	*str;
	int		nb;
	int		num_width;
	int		negative;
	int		minus_flag;

	negative = 0;
	minus_flag = 0;
	nb = va_arg(DATA->args, int);
	if (nb < 0)
	{
		nb *= -1;
		negative = 1;
	}
	num_width = get_tens(nb);
	printf("num_width %d\n", num_width);
	if (DATA->converter_flag[0] == '-')
		minus_flag = 1;
	write(1, "HERE\n", 5);
	print_d(DATA, nb, num_width, minus_flag);
	return (DATA);
}
