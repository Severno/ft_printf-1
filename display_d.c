/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 23:44:21 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/18 01:12:47 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_DATA *display_d(t_DATA *DATA)
{
	char	*str;
	if (!(DATA->specifier_flag == 'd'))
		return (NULL);
	
	str = ft_itoa(va_arg(DATA->args, int));
	ft_putstr(str);
	return (DATA);
}
