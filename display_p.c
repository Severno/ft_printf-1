/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 01:57:01 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/25 16:01:44 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	get_num(t_DATA *DATA)
{
	uintmax_t	num;

	num = (unsigned long)(va_arg(DATA->args, unsigned long int));
	num = (uintmax_t)num;
	return (num);
}

static t_DATA		*print_u(t_DATA *DATA, uintmax_t  num, char *str, int align_left)
{
	int			not_blank;
	int			num_width;

	num_width = ft_strlen(str) + 2;
	not_blank = num_width;
	DATA->len += (not_blank <= DATA->field_width) ? DATA->field_width : not_blank;
	if (!align_left)
		display_gap(DATA, ' ', DATA->field_width - not_blank, 0);
	write(1, "0x", 2);
	ft_putstr(str);
	if (align_left)
		display_gap(DATA, ' ', DATA->field_width - not_blank, 0);
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
	print_u(DATA, num, str, align_left);
	return (DATA);
}
