/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:01:33 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/25 19:09:29 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_DATA *display_percent(t_DATA *DATA)
{
      if (DATA->converter_flag[0] != '-')
		  display_gap(DATA, ' ', DATA->field_width - 1, 1);
	  write(1, "%", 1);
      if (DATA->converter_flag[0] == '-')
		  display_gap(DATA, ' ', DATA->field_width - 1, 1);
      DATA->len++;
  return(DATA);
}
