/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 19:49:36 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/25 16:02:56 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_DATA	*display_gap(t_DATA *DATA, char c, int len, int update_len)
{
	char	*str;

	if (len > 0)
	{
		if (update_len)
			DATA->len += len;
		if ((str = ft_strnew(len)))
		{
			ft_memset(str, c, len);
			write(1, str, len);
			free(str);
		}
	}
	return (DATA);
}
