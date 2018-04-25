/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:08:45 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/25 15:09:02 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int treatement(t_DATA *DATA)
{
    size_t j;
    j = DATA->i++;

    double_percent(DATA);
    parse_converter(DATA);
    parse_field_width(DATA);
    parse_precision(DATA);
    parse_arguments(DATA);
    parse_specifier(DATA);
    switch_display(DATA);
    if (j == DATA->i)
        DATA->len = that_error(1);
    return (DATA->len);
}
