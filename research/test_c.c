/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 19:48:43 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/16 19:48:47 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "research.h"

void	test_c(void)
{
	int		count = 0;

	while (c[count])
		P("c[%c]", c[count]);
