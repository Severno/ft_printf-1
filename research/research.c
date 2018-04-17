/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 14:41:14 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/16 20:07:13 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "research.h"

/* GLOBAL VARIABLES */

/* Good string */
char	s1[25] = "Hello, world!";
char	s2[5] = "e";
char	s3[5] = "\0";


/* Char */
char	c[8] = "ZeP\tq87\0";

/* Int */
int		i1 = -42;
int		i2 = 0;
int		i3 = 42;

int		main(void)
{


	test_c();
	return (0);
}

void	test_c(void)
{
	int count = -1;
	while (c[++count])
		P("c[%c]", c[count]);
}
