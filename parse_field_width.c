/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_field_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:45:09 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/25 19:45:14 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_DATA *parse_field_width(t_DATA *DATA)
{
   while (DATA->f_treat[DATA->i] >= '0' && DATA->f_treat[DATA->i] <= '9')
    {
      DATA->field_width *= 10;
      DATA->field_width += (DATA->f_treat[DATA->i] - 48);
      DATA->i++;
    }
  return(DATA);
}
