/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:46:06 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/28 03:45:53 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

/*
** format: string (first ft_printf parameter).
** f_copy: copy of format.
** f_treat: copy of format.
** args: stores caradic arguments.
** len: ft_printf return value (number of printed characters).
** i: position of read in format string.
** masks contain strings of chars for the respective flags, used for matching.
*/

typedef struct		s_DATA
{
					const char *format;
					char *f_copy;
					char *f_treat;
					
					va_list args;
					int len;
					size_t i;

					long int precision;
					long int field_width;
					char specifier_flag;
					char converter_flag[6];
					char argument_flag[2];

					char *specifier_mask;
					char *converter_mask;
					char *argument_mask;
}					t_DATA;

int					ft_printf(const char *format, ...);
int					treatement(t_DATA *DATA);
int					parser(t_DATA *DATA);

t_DATA				*initialize(t_DATA *DATA);
t_DATA				*reinitialize(t_DATA *DATA);

t_DATA				*parse_converter(t_DATA *DATA);
t_DATA				*parse_field_width(t_DATA *DATA);
t_DATA				*parse_precision(t_DATA *DATA);
t_DATA				*parse_arguments(t_DATA *DATA);
t_DATA				*parse_specifier(t_DATA *DATA);
t_DATA				*switch_display(t_DATA *DATA);

t_DATA				*display_d(t_DATA *DATA);
t_DATA				*display_s(t_DATA *DATA);
t_DATA				*display_c(t_DATA *DATA);
t_DATA				*display_u(t_DATA *DATA);
t_DATA				*display_x(t_DATA *DATA);
t_DATA				*display_o(t_DATA *DATA);
t_DATA				*display_p(t_DATA *DATA);
t_DATA				*display_ws(t_DATA *DATA);
t_DATA				*display_other(t_DATA *DATA);
void				display_wchar(wint_t c, t_DATA *DATA);
void				display_gap(t_DATA *DATA, char c, int len, int update_len);

#endif
