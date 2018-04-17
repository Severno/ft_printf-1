/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 22:58:38 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/16 19:49:20 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESEARCH_H
# define RESEARCH_H

# include <stdio.h>
# include <stdarg.h>
# include <string.h>

/*			PRINTF SETUP					*/
# define P(...); printf(__VA_ARGS__); printf("\n"); \
printf(__VA_ARGS__); printf("\n\n\n");
//# define F(...); printf("\n");


/*			TABULATION FORMATTING			*/
# define TITLE(...); printf("\n\n\n\n\t\t--"); printf(__VA_ARGS__); printf("--\n");
# define HEAD(...); printf("\n\t-"); printf(__VA_ARGS__); printf("-\n");

void			test_c(void);


#endif
