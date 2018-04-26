/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 02:46:02 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/25 22:36:42 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_DATA			*switch_display(t_DATA *DATA)
{
	char	*flag;

	flag = &DATA->specifier_flag;
	if(*flag == 'd' || *flag == 'i' || *flag == 'D')
		display_d(DATA);
	else if(*flag == 'c')
		display_c(DATA);
	else if(*flag == 's')
		display_s(DATA);
	else if(*flag == 'u' || *flag == 'U')
		display_u(DATA);
	else if(*flag == 'x' || *flag == 'X')
		display_x(DATA);
	else if(*flag == 'o' || *flag == 'O')
		display_o(DATA);
	else if(*flag == 'p')
		display_p(DATA);
	else
		display_other(DATA);
	return(DATA);
}
