/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:52:37 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/27 17:33:25 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int ft_printf(const char *format, ...)
{
	setlocale(LC_ALL, "");
    t_DATA *DATA;
    DATA = (t_DATA*)malloc(sizeof(t_DATA));

    DATA->format = format;

    DATA = initialize(DATA);
    if (format)
    {
        va_start(DATA->args, format);
        DATA->len = parser(DATA);
        va_end(DATA->args);
    }
    return(DATA->len);
}
