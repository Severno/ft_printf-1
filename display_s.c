/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 03:25:05 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/22 19:38:35 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		print_space(t_DATA *DATA, int len)
{
	while ((DATA->field_width--) > len)
	{
		write (1, " ", 1);
		DATA->len += 1;
	}
}

t_DATA			*display_s(t_DATA *DATA)
{
	char		*s;
	int			i;
	int			len;
	char		*tmp;

	i = 0;
	s = va_arg(DATA->args, char *);
	if (DATA->precision && s)
		s = ft_strndup(s, DATA->precision);
	else if (!DATA->precision && s)
		s = ft_strdup(s);
	else if (DATA->precision && !s)
		s = ft_strndup("(null)", DATA->precision);
	else if (!DATA->precision && !s)
		s = ft_strdup("(null)");
	len = ft_strlen(s);
	DATA->len += len;
	if (DATA->converter_flag[0] != '-')
		print_space(DATA, len);
	ft_putstr(s);
	if (DATA->converter_flag[0] == '-')
		print_space(DATA, len);
	free (s);
	return (DATA);
}
