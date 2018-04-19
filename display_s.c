/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 03:25:05 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/19 04:01:41 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_DATA			*display_s(t_DATA *DATA)
{
	char		*s;
	int			i;

	i = 0;
	s = va_arg(DATA->args, char *);
	if (DATA->precision)
	{
		while (DATA->precision-- > 0 && s != '\0')
		{
			write(1, s, 1);
			s++;
		}
	}
	else
		ft_putstr(s);
	return (DATA);
}
