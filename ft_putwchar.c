/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 00:15:16 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/27 00:34:10 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		oct_4(unsigned long c)
{
	unsigned char a1;
	unsigned char a2;
	unsigned char a3;
	unsigned char a4;

	printf("C=[%ld]\n", c);
	a1 = (c >> 18) + 240;
	a2 = ((c >> 12) & 63) + 128;
	a3 = ((c >> 6) & 63) + 128;
	a4 = ((c & 63) + 128);

	printf("A1=[%u]\n", a1);
	printf("A2=[%u]\n", a2);
	printf("A3=[%u]\n", a3);
	printf("A4=[%u]\n", a4);

	write (1, &a1, 1);
	write (1, &a2, 1);
	write (1, &a3, 1);
	write (1, &a4, 1);
}

static void		oct_3(unsigned long c)
{
	write (1, &c, 1);
}

static void		oct_2(unsigned long c)
{
	write (1, &c, 1);
}

static void		oct_1(unsigned long c)
{
	write (1, &c, 1);
}

int				main(void)
{
	unsigned long c;

	c = 125011;
	
	//c = 225;
	//write(1, &c, 1);
	//c = 136;
	//write(1, &c, 1);
	//c = 180;
	//write(1, &c, 1);
	//c = 10;
	//write(1, &c, 1);

	if (c <= 127)
		oct_1(c);
	if (c >= 127 && c <= 2047)
		oct_2(c);
	if (c >= 2048 && c <= 65535)
		oct_3(c);
	if (c >= 65536 && c <= 2097151)
		oct_4(c);
	//
	////
	write (1, "\n", 1);
	return (0);
}
