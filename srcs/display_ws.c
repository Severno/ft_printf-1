/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ws.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 03:25:05 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/29 10:05:03 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <ctype.h>
#include <stdlib.h>

static int		char_len(wchar_t c)
{
	int len;

	if (c <= 127)
		len = 1;
	else if (c >= 127 && c <= 2047)
		len = 2;
	else if (c >= 2048 && c <= 65535)
		len = 3;
	else
		len = 4;
	return (len);
}

static wchar_t	*wstrndup(wchar_t *s1, size_t n)
{
	wchar_t	*s2;
	size_t	i;

	i = 0;
	if (!(s2 = (wchar_t *)malloc(sizeof(wchar_t) * n + 1)))
		return (NULL);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

static wchar_t	*wstrdup(wchar_t *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (wstrndup(str, len));
}

t_tab			*display_ws(t_tab *tab)
{
	wchar_t		*s;
	int			store;
	int			i;
	int			len;

	i = 0;
	len = 0;
	store = 0;
	s = (wchar_t *)va_arg(tab->args, wchar_t *);
	if (tab->precision > -1 && s)
		s = wstrndup(s, tab->precision);
	else if (tab->precision == -1 && s)
		s = wstrdup(s);
	else if (tab->precision > -1 && !s)
		s = wstrndup(L"(null)", tab->precision);
	else if (tab->precision == -1 && !s)
		s = wstrdup(L"(null)");
	while (s[i])
	{
		if (tab->precision > -1 && (store += char_len(s[i])) > tab->precision)
			break ;
		len += char_len(s[i++]);
	}
	if (tab->convert[3] == '0' && tab->convert[0] != '-')
		display_gap(tab, '0', tab->field_width - len, 1);
	else if (tab->convert[0] != '-')
		display_gap(tab, ' ', tab->field_width - len, 1);
	i = 0;
	store = 0;
	while (s[i])
	{
		if (tab->precision > -1 && (store += char_len(s[i])) > tab->precision)
			break ;
		display_wchar(s[i++], tab);
	}
	if (tab->convert[0] == '-')
		display_gap(tab, ' ', tab->field_width - len, 1);
	free(s);
	return (tab);
}
