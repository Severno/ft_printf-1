/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 23:44:21 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/28 01:53:44 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t		get_num(t_DATA *DATA)
{
	intmax_t	num;

	if (DATA->specifier_flag == 'D')
		num = (long)(va_arg(DATA->args, long int));
	else if (ft_strcmp(DATA->argument_flag, "hh") == 0)
		num = (signed char)(va_arg(DATA->args, int));
	else if (ft_strcmp(DATA->argument_flag, "h") == 0)
		num = (short)(va_arg(DATA->args, int));
	else if (ft_strcmp(DATA->argument_flag, "ll") == 0)
		num = (long long)(va_arg(DATA->args, long long int));
	else if (ft_strcmp(DATA->argument_flag, "l") == 0)
		num = (long)(va_arg(DATA->args, long int));
	else if (ft_strcmp(DATA->argument_flag, "j") == 0)
		num = (intmax_t)(va_arg(DATA->args, intmax_t));
	else if (ft_strcmp(DATA->argument_flag, "z") == 0)
		num = (size_t)(va_arg(DATA->args, size_t));
	else
		num = (int)(va_arg(DATA->args, int));
	num = (intmax_t)num;
	return (num);
}


static int		get_tens(intmax_t num)
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

static t_DATA		*print_d(t_DATA *DATA, intmax_t  num, int num_width, int align_left)
{
	int			not_blank;
	char		negatvity_placeholder;
	int			is_negative;

	is_negative = 0;
	if (num < 0)
		is_negative = 1;
	if (is_negative && num != (-9223372036854775807 - 1))
		num *= -1;
	negatvity_placeholder = get_negatvity_placeholder(DATA, is_negative);
	not_blank = num_width;
	if (num_width <= DATA->precision && DATA->precision >= 0)
		not_blank = DATA->precision;
	if (negatvity_placeholder)
		not_blank++;
	DATA->len += (not_blank <= DATA->field_width) ? DATA->field_width : not_blank;
	if (!align_left)
		display_gap(DATA, ' ', DATA->field_width - not_blank, 0);
	if (negatvity_placeholder)
		write(1, &negatvity_placeholder, 1);
	display_gap(DATA, '0', DATA->precision - num_width, 0);
	if (num != (-9223372036854775807 - 1))
		ft_putnbrmax_fd(num, 1);
	else
	{
		write(1, "9223372036854775808", 19);
		DATA->len += 18;
	}
	if (align_left)
		display_gap(DATA, ' ', DATA->field_width - not_blank, 0);
	return (DATA);
}

t_DATA			*display_d(t_DATA *DATA)
{
	intmax_t	num;
	int			num_width;
	int			align_left;

	align_left = 0;
	num = get_num(DATA);
	if (num == 0 && DATA->precision == 0)
	{
		if (DATA->converter_flag[1] == '+')
			display_wchar('+', DATA);
		if (DATA->converter_flag[2] == ' ')
			display_wchar(' ', DATA);
		display_gap(DATA, ' ', DATA->field_width, 1);
		return (DATA);
	}
	num_width = get_tens(num);
	if (DATA->converter_flag[0] == '-')
		align_left = 1;
	if (DATA->converter_flag[3] == '0' && DATA->precision == -1  && !DATA->converter_flag[0])
	{
		DATA->precision = DATA->field_width;
		if (num < 0 || DATA->converter_flag[2] || DATA->converter_flag[1] || DATA->converter_flag[0]) 
			DATA->precision--;
	}
	print_d(DATA, num, num_width, align_left);
	return (DATA);
}
