/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 14:41:14 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/16 18:24:51 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "research.h"

/* GLOBAL VARIABLES */

/* Good string */
char	s1[25] = "Hello, world!";
char	s2[5] = "e";
char	s3[5] = "\0";



/* Char */
char	c1 = 'Z';
char	c2 = 33; /* Exclamation Mark */
char	c3 = '\0';


/* Int */
int		i1 = 2;
int		i2 = 0;
int		i3 = 42;

long long int l = 1;





//unsigned

int		main(void)
{
	//d
	TITLE("STRINGS");
	HEAD("Basic");
	P("s[%i]", i1);
	
	P("s[%5i]", i2);
	
	P("s[%5i]", i3);
	return(0);
}
