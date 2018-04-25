/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 02:46:02 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/25 19:46:44 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_DATA			*switch_display(t_DATA *DATA)
{
	char	*flag;

	flag = &DATA->specifier_flag;
	if(*flag == 'd' || *flag == 'i' || *flag == 'D')
		display_d(DATA);
	if(*flag == 'c')
		display_c(DATA);
	if(*flag == 's')
		display_s(DATA);
	if(*flag == 'u' || *flag == 'U')
		display_u(DATA);
	if(*flag == 'x' || *flag == 'X')
		display_x(DATA);
	if(*flag == 'o' || *flag == 'O')
		display_o(DATA);
	if(*flag == 'p')
		display_p(DATA);
	if(*flag == '%')
		display_percent(DATA);
	return(DATA);
}
