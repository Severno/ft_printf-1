/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 18:40:25 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/27 18:40:36 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		oct_4(wint_t c)
{
	unsigned char a1; 
	unsigned char a2;
	unsigned char a3;
	unsigned char a4;

	a1 = (c >> 18) + 240;
	a2 = ((c >> 12) & 63) + 128;
	a3 = ((c >> 6) & 63) + 128;
	a4 = ((c & 63) + 128);

	write (1, &a1, 1);
	write (1, &a2, 1);
	write (1, &a3, 1);
	write (1, &a4, 1);
}

static void		oct_3(wint_t c)
{
	unsigned char a1;
	unsigned char a2;
	unsigned char a3;

	a1 = (c >> 12) + 224;
	a2 = ((c >> 6) & 63) + 128;
	a3 = ((c & 63) + 128);

	write (1, &a1, 1);
	write (1, &a2, 1);
	write (1, &a3, 1);
}

static void		oct_2(wint_t c)
{
	unsigned char a1;
	unsigned char a2;

	a1 = (c >> 6) + 192;
	a2 = ((c & 63) + 128);

	write (1, &a1, 1);
	write (1, &a2, 1);
}

static void		oct_1(wint_t c)
{
	write (1, &c, 1);
}

void			display_wchar(wint_t c)
{
	if (c <= 127)
		oct_1(c);
	if (c >= 127 && c <= 2047)
		oct_2(c);
	if (c >= 2048 && c <= 65535)
		oct_3(c);
	if (c >= 65536 && c <= 2097151)
		oct_4(c);
}
