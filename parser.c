/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:00:32 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/25 15:00:38 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int parser(t_DATA *DATA)
{
    while(DATA->f_copy[DATA->i] != '\0')
    {
        if(DATA->f_copy[DATA->i]=='%')
        {
            reinitialize(DATA);
            treatement(DATA);
        }
        else
        {
          write(1, &DATA->f_copy[DATA->i], 1);
          DATA->len++;
        }
        DATA->i++;
    }
    // 
	//
	// debug part
/*
    printf("\n\n");
    printf("precision = %ld\n", DATA->precision);
    printf("field = %ld\n",DATA->field_width);
    printf("specifier_flag = %c\n", DATA->specifier_flag);
    printf("converter_flg = %s\n", DATA->converter_flag);
    printf("argument flag = %s\n", DATA->argument_flag);
    printf("len = %d\n", DATA->len);
    printf("\n\n");
*/
	//
	//
    return(DATA->len);
}
