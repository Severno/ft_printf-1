/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:01:33 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/23 16:53:30 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_DATA *display_percent(t_DATA *DATA)
{
      if (DATA->converter_flag[0] != '-')
	  {
		  while (DATA->field_width-- > 1)
		  {
			  write(1, " ", 1);
			  DATA->len++;
		  }
	  }
	  write(1, "%", 1);
      if (DATA->converter_flag[0] == '-')
	  {
		  while (DATA->field_width-- > 1)
		  {
			  write(1, " ", 1);
			  DATA->len++;
		  }
	  }
      DATA->len++;
  return(DATA);
}
