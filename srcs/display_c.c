/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 02:46:02 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/28 17:33:46 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <ctype.h>

t_DATA			*display_c(t_DATA *DATA)
{
	wint_t		c;

	if (ft_strcmp(DATA->argument_flag, "l") == 0)
		c = (unsigned long)va_arg(DATA->args, unsigned long);
	else if (DATA->specifier_flag == 'C')
		c = (wchar_t)va_arg(DATA->args, wint_t);
	else
		c = (char)va_arg(DATA->args, int);
	c = (wint_t)c;
	if (DATA->converter_flag[3] == '0' && DATA->converter_flag[0] != '-')
		display_gap(DATA, '0', DATA->field_width - 1, 1);	
	else if (DATA->converter_flag[0] != '-')
		display_gap(DATA, ' ', DATA->field_width - 1, 1);	
	display_wchar(c, DATA);
	if (DATA->converter_flag[0] == '-')
		display_gap(DATA, ' ', DATA->field_width - 1, 1);
	return (DATA);
}
