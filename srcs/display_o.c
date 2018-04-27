/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 01:30:20 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/26 17:01:26 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			print_leading_zero(uintmax_t num, char hash)
{
	if (hash == '#' && num)
		write (1, "0", 1);
}

static uintmax_t	get_num(t_DATA *DATA)
{
	uintmax_t	num;

	if (DATA->specifier_flag == 'O')
		num = (unsigned long)(va_arg(DATA->args, unsigned long int));
	else if (ft_strcmp(DATA->argument_flag, "hh") == 0)
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

static t_DATA		*print_u(t_DATA *DATA, uintmax_t  num, char *str, int align_left)
{
	int			not_blank;
	int			num_width;

	num_width = ft_strlen(str);
	not_blank = num_width;
	if (num_width <= DATA->precision && DATA->precision > 0)
		not_blank = DATA->precision;
	if (DATA->converter_flag[4] == '#' && num)
		not_blank++;
	DATA->len += (not_blank <= DATA->field_width) ? DATA->field_width : not_blank;
	if (!align_left)
		display_gap(DATA, ' ', DATA->field_width - not_blank, 0);
	display_gap(DATA, '0', DATA->precision - num_width, 0);
	print_leading_zero(num, DATA->converter_flag[4]);
	ft_putstr(str);
	free(str);
	if (align_left)
		display_gap(DATA, ' ', DATA->field_width - not_blank, 0);
	return (DATA);
}

t_DATA			*display_o(t_DATA *DATA)
{
	char		*str;
	uintmax_t	num;
	int			align_left;

	align_left = 0;
	num = get_num(DATA);
	if (num == 0 && DATA->precision == 0 && DATA->converter_flag[4] != '#')
	{
		display_gap(DATA, ' ', DATA->field_width, 1);
		return (DATA);
	}
	if (!(str = ft_itoa_base(num, 8, 'a')))
		return (NULL);
	if (DATA->converter_flag[0] == '-')
		align_left = 1;
	if (DATA->converter_flag[3] == '0' && DATA->precision == -1 && !DATA->converter_flag[0])
		DATA->precision = DATA->field_width;
	print_u(DATA, num, str, align_left);
	return (DATA);
}