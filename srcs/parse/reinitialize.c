/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinitialize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:58:20 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/25 20:57:36 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_DATA *reinitialize(t_DATA *DATA)
{
	DATA->specifier_flag = '\0';
	DATA->converter_flag[0] = '\0';
	DATA->converter_flag[1] = '\0';
	DATA->converter_flag[2] = '\0';
	DATA->converter_flag[3] = '\0';
	DATA->converter_flag[4] = '\0';
	DATA->converter_flag[5] = '\0';
	DATA->argument_flag[0] = '\0';
	DATA->argument_flag[1] = '\0';
	DATA->precision = -1;
	DATA->field_width = 0;

	return(DATA);
}
