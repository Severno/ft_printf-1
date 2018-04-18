/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 23:44:21 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/19 01:13:39 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		get_tens(int num)
{
	int tens;

	if (num < 0)
		num *= -1;
	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}

static char		get_negatvity_placeholder(t_DATA *DATA, int is_negative)
{
	char	*tmp;

	tmp = DATA->converter_flag;
	if (is_negative)
		return ('-');
	if (tmp[1] == '+')
		return ('+');
	if (tmp[2] == ' ')
		return (' ');
	return ('\0');
}

t_DATA			*print_d(t_DATA *DATA, int num, int num_width, int align_left)
{
	int			not_blank;
	char		negatvity_placeholder;
	int			is_negative;

	is_negative = 0;
	if (num < 0)
		is_negative = 1;
	if (is_negative)
		num *= -1;
	negatvity_placeholder = get_negatvity_placeholder(DATA, is_negative);
	not_blank = num_width;
	if (num_width <= DATA->precision)
		not_blank = DATA->precision;
	if (negatvity_placeholder)
		not_blank++;
	while (!align_left && DATA->field_width-- > not_blank)
		write(1, " ", 1);
	if (negatvity_placeholder)
		write(1, &negatvity_placeholder, 1);
	while (DATA->precision-- > num_width)
		write(1, "0", 1);
	ft_putnbr(num);
	while (align_left && DATA->field_width-- > not_blank)
		write(1, " ", 1);
	return (DATA);
}

t_DATA			*display_d(t_DATA *DATA)
{
	char	*str;
	int		num;
	int		num_width;
	int		align_left;

	align_left = 0;
	num = va_arg(DATA->args, int);
	num_width = get_tens(num);
	if (DATA->converter_flag[0] == '-')
		align_left = 1;
	if (DATA->converter_flag[3] == '0' && !DATA->precision && !DATA->converter_flag[0])
	{
		DATA->precision = DATA->field_width;
		if (num < 0)
			DATA->precision--;
	}
	print_d(DATA, num, num_width, align_left);
	return (DATA);
}
