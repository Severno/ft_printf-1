/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:45:26 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/25 20:57:05 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_DATA *parse_precision(t_DATA *DATA)
{
	while (DATA->f_treat[DATA->i] == '.')
	{
		DATA->i++;
		DATA->precision = 0;
	}
	while (DATA->f_treat[DATA->i] >= '0' && DATA->f_treat[DATA->i] <= '9')
	{
		DATA->precision *= 10;
		DATA->precision += (DATA->f_treat[DATA->i] - 48);
		DATA->i++;
	}
	return (DATA);
}
