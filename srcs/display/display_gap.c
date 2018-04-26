/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 19:49:36 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/25 19:07:52 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display_gap(t_DATA *DATA, char c, int len, int update_len)
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
}
