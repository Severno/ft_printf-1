/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 01:57:01 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/22 15:44:40 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static uintmax_t	get_num(t_DATA *DATA)
{
	uintmax_t	num;

	num = (unsigned long)(va_arg(DATA->args, unsigned long int));
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

static t_DATA		*print_u(t_DATA *DATA, uintmax_t  num, char *str, int align_left)
{
	int			not_blank;
	int			num_width;

	num_width = ft_strlen(str) + 2;
	not_blank = num_width;
	if (num_width <= DATA->precision)
		not_blank = DATA->precision;
	DATA->len += (not_blank <= DATA->field_width) ? DATA->field_width : not_blank;
	while (!align_left && DATA->field_width-- > not_blank)
		write(1, " ", 1);
	write(1, "0x", 2);
	while (DATA->precision-- > num_width)
		write(1, "0", 1);
	ft_putstr(str);
	while (align_left && DATA->field_width-- > not_blank)
		write(1, " ", 1);
	return (DATA);
}

t_DATA			*display_p(t_DATA *DATA)
{
	char		*str;
	uintmax_t	num;
	int			num_width;
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
