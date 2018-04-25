/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:44:14 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/25 15:44:18 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <limits.h>

int		main(void)
{
	
	int		val;
	unsigned int	p;

	p = 4294967295;

	val = ft_printf("%");
									printf("[%d]\n\n", val);
	val =    printf("%");
									printf("[%d]\n\n", val);

/*
	char str[] = "yoyoyoyoyo";
	int val;

	val = ft_printf("Hello %10.0s\n", str);
									printf("[%d]\n\n", val);
	val =    printf("Hello %10.0s\n", str);
									printf("[%d]\n\n", val);
	return (0);
	*/
}
