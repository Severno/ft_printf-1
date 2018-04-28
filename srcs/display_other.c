/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:01:33 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/28 20:54:45 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_DATA	*display_percent(t_DATA *DATA)
{
	if (DATA->converter_flag[3] == '0' && DATA->precision <= 0  && !DATA->converter_flag[0])
	{
		DATA->precision = DATA->field_width;
		DATA->field_width = 0;
	}
	if (DATA->converter_flag[0] != '-')
		display_gap(DATA, ' ', DATA->field_width - 1, 1);
	if (DATA->converter_flag[3] == '0')
		display_gap(DATA, '0', DATA->precision - 1, 1);
	write(1, "%", 1);
	if (DATA->converter_flag[0] == '-')
		display_gap(DATA, ' ', DATA->field_width - 1, 1);
	DATA->len++;
	return(DATA);
}

t_DATA			*display_other(t_DATA *DATA)
{
	if (DATA->f_treat[DATA->i] == '%')
	{
		display_percent(DATA);
		return (DATA);
	}
	if (DATA->converter_flag[3] == '0' && DATA->precision <= 0  && !DATA->converter_flag[0])
	{
		DATA->precision = DATA->field_width;
		DATA->field_width = 0;
	}
	if (DATA->converter_flag[0] != '-')
		display_gap(DATA, ' ', DATA->field_width - 1, 1);
	if (DATA->converter_flag[3] == '0')
		display_gap(DATA, '0', DATA->precision - 1, 1);
	write(1, &DATA->f_copy[DATA->i], 1);
	if (DATA->converter_flag[0] == '-')
		display_gap(DATA, ' ', DATA->field_width - 1, 1);
	DATA->len++;
	return(DATA);
}
