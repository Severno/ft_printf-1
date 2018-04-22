/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 22:30:17 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/22 18:11:10 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void			print_leading_zero(uintmax_t num, char hash, char x)
{
	if (num)
	{
		if (hash == '#' && x == 'x')
			write (1, "0x", 2);
		if (hash == '#' && x == 'X')
			write (1, "0X", 2);
	}
}

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

static t_DATA		*print_u(t_DATA *DATA, uintmax_t  num, char *str, int align_left)
{
	int			not_blank;
	int			num_width;

	num_width = ft_strlen(str);
	if (DATA->converter_flag[4] == '#' && num)
		num_width += 2;
	not_blank = num_width;
	if (num_width <= DATA->precision)
		not_blank = DATA->precision;
	DATA->len += (not_blank <= DATA->field_width) ? DATA->field_width : not_blank;
	while (!align_left && DATA->field_width-- > not_blank)
		write(1, " ", 1);
	print_leading_zero(num, DATA->converter_flag[4], DATA->specifier_flag);
	while (DATA->precision-- > num_width)
		write(1, "0", 1);
	if (DATA->specifier_flag == 'x')
		ft_putstr(str);
	else if (DATA->specifier_flag == 'X')
		ft_putstr(ft_itoa_base(num, 16, 'A'));
	free(str);
	while (align_left && DATA->field_width-- > not_blank)
		write(1, " ", 1);
	return (DATA);
}

t_DATA			*display_x(t_DATA *DATA)
{
	char		*str;
	uintmax_t	num;
	int			align_left;

	align_left = 0;
	num = get_num(DATA);
	if (!(str = ft_itoa_base(num, 16, 'a')))
		return (NULL);
	if (DATA->converter_flag[0] == '-')
		align_left = 1;
	if (DATA->converter_flag[3] == '0' && !DATA->precision && !DATA->converter_flag[0])
		DATA->precision = DATA->field_width;
	print_u(DATA, num, str, align_left);
	return (DATA);
}
