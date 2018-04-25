/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:42:35 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/25 19:42:41 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_DATA *double_percent(t_DATA *DATA)
{
  if(DATA->f_treat[DATA->i] == '%' && DATA->f_treat[DATA->i - 1] != '%')
  {
      write(1, "%", 1);
      DATA->len++;
	  DATA->specifier_flag = '\0';
  }
  return(DATA);
}
