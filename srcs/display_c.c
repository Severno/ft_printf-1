/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 02:46:02 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/27 08:53:54 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <ctype.h>

t_DATA			*display_c(t_DATA *DATA)
{
	wchar_t		c;

	if (ft_strcmp(DATA->argument_flag, "l") == 0)
		c = (wchar_t)va_arg(DATA->args, wint_t);
	else if (DATA->specifier_flag == 'C')
		c = (wchar_t)va_arg(DATA->args, wint_t);
	else //(DATA->specifier_flag == 'c')
		c = (char)va_arg(DATA->args, int);
	if (DATA->converter_flag[0] != '-')
		display_gap(DATA, ' ', DATA->field_width - 1, 1);	
	ft_putwchar(c);
	if (DATA->converter_flag[0] == '-')
		display_gap(DATA, ' ', DATA->field_width - 1, 1);
	DATA->len++;
	return (DATA);
}
