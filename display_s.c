/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 03:25:05 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/22 17:35:02 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_DATA			*display_s(t_DATA *DATA)
{
	char		*s;
	int			i;
	int			len;

	i = 0;
	if (DATA->precision)
		s = ft_strndup(va_arg(DATA->args, char *), DATA->precision);
	else
		s = ft_strdup(va_arg(DATA->args, char *));
	len = ft_strlen(s);
	DATA->len += len;
	while ((DATA->field_width--) > len)
	{
		write (1, " ", 1);
		DATA->len += 1;
	}
	ft_putstr(s);
	free (s);
	return (DATA);
}
