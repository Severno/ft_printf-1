/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:44:48 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/25 19:44:51 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_DATA *parse_arguments(t_DATA *DATA)
{
  size_t i;
  size_t j;

  i = 0;
  j = 0;
  while(DATA->argument_mask[i] != '\0')
    {
      while(DATA->argument_mask[i] == DATA->f_treat[DATA->i])
      {
        DATA->argument_flag[j] = DATA->f_treat[DATA->i];
        DATA->argument_flag[j+1] = '\0';
        DATA->i++;
        j++;
      }
      i++;
    }
    return(DATA);
}
