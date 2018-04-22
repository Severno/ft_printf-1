/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 02:46:02 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/22 21:17:32 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		print_space(t_DATA *DATA, int len)
{
	while (--len > -1 && len)
	{
		write(1, " ", 1);
		DATA->len++;
	}
}

t_DATA			*display_c(t_DATA *DATA)
{
	char		c;

	c = va_arg(DATA->args, int);
	if (DATA->converter_flag[0] != '-')
		print_space(DATA, DATA->field_width);
	write(1, &c, 1);
	if (DATA->converter_flag[0] == '-')
		print_space(DATA, DATA->field_width);
	DATA->len++;
	return (DATA);
}
