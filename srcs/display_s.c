/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 03:25:05 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/26 14:56:27 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_DATA			*display_s(t_DATA *DATA)
{
	char		*s;
	int			i;
	int			len;

	i = 0;
	s = va_arg(DATA->args, char *);
	if (DATA->precision > -1 && s)
		s = ft_strndup(s, DATA->precision);
	else if (DATA->precision == -1 && s)
		s = ft_strdup(s);
	else if (DATA->precision > -1 && !s)
		s = ft_strndup("(null)", DATA->precision);
	else if (DATA->precision == -1&& !s)
		s = ft_strdup("(null)");
	len = ft_strlen(s);
	DATA->len += len;
	if (DATA->converter_flag[0] != '-')
		display_gap(DATA, ' ', DATA->field_width - len, 1);
	ft_putstr(s);
	if (DATA->converter_flag[0] == '-')
		display_gap(DATA, ' ', DATA->field_width - len, 1);
	free (s);
	return (DATA);
}
