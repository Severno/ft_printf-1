/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:04:42 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/25 15:06:18 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_DATA *initialize(t_DATA *DATA)
{
  DATA->len = 0;
  DATA->i = 0;
  DATA->specifier_mask = "scSCdDiuUoOxXbp%";
  DATA->converter_mask = "-+ 0#";
  DATA->argument_mask = "lhjz";
  DATA->f_treat = (char *)DATA->format;
  DATA->f_copy = (char *)DATA->format;
  return(DATA);
}
