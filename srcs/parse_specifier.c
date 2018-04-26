/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:45:37 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/25 20:58:00 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_DATA *parse_specifier(t_DATA *DATA)
{
	size_t i;

	i = 0;
	while(DATA->specifier_mask[i] != '\0')
	{
		if(DATA->specifier_mask[i] == DATA->f_treat[DATA->i])
			DATA->specifier_flag = DATA->specifier_mask[i];
		i++;
	}
	return(DATA);
}
