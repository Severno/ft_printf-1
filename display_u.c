/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 00:41:03 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/23 23:43:16 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static uintmax_t	get_num(t_DATA *DATA)
{
	uintmax_t	num;

	if (ft_strcmp(DATA->argument_flag, "hh") == 0)
		num = (unsigned char)(va_arg(DATA->args, unsigned int));
	else if (ft_strcmp(DATA->argument_flag, "h") == 0)
		num = (unsigned short)(va_arg(DATA->args, unsigned int));
	else if (ft_strcmp(DATA->argument_flag, "ll") == 0)
		num = (unsigned long long)(va_arg(DATA->args, unsigned long long int));
	else if (ft_strcmp(DATA->argument_flag, "l") == 0)
		num = (unsigned long)(va_arg(DATA->args, unsigned long int));
	else if (ft_strcmp(DATA->argument_flag, "j") == 0)
		num = (uintmax_t)(va_arg(DATA->args, uintmax_t));
	else if (ft_strcmp(DATA->argument_flag, "z") == 0)
		num = (size_t)(va_arg(DATA->args, size_t));
	else
		num = (unsigned int)(va_arg(DATA->args, unsigned int));
	num = (uintmax_t)num;
	return (num);
}


static int		get_tens(uintmax_t num)
{
	int tens;

	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}

static t_DATA		*print_u(t_DATA *DATA, uintmax_t  num, int num_width, int align_left)
{
	int			not_blank;

	not_blank = num_width;
	if (num_width <= DATA->precision)
		not_blank = DATA->precision;
	DATA->len += (not_blank <= DATA->field_width) ? DATA->field_width : not_blank;
	if (!align_left)
		display_gap(DATA, ' ', DATA->field_width - not_blank, 0);
	display_gap(DATA, '0', DATA->precision - num_width, 0);
	ft_putnbrumax_fd(num, 1);
	if (align_left)
		display_gap(DATA, ' ', DATA->field_width - not_blank, 0);	
	return (DATA);
}

t_DATA			*display_u(t_DATA *DATA)
{
	char		*str;
	uintmax_t	num;
	int			num_width;
	int			align_left;

	align_left = 0;
	num = get_num(DATA);
	num_width = get_tens(num);
	if (DATA->converter_flag[0] == '-')
		align_left = 1;
	if (DATA->converter_flag[3] == '0' && !DATA->precision && !DATA->converter_flag[0])
		DATA->precision = DATA->field_width;
	print_u(DATA, num, num_width, align_left);
	return (DATA);
}
