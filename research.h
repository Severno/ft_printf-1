/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 22:58:38 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/15 23:01:49 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESEARCH_H
# define RESEARCH_H

# include <stdio.h>
# include <stdarg.h>
# include <string.h>

/*			PRINTF SETUP					*/
# define P(...); printf(__VA_ARGS__);
# define F(...); printf(__VA_ARGS__);
//# define F(...);


/*			TABULATION FORMATTING			*/
# define TITLE(...); printf("\n\n\n\n\t\t--"); printf(__VA_ARGS__); printf("--\n");

#endif
