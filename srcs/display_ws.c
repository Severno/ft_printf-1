/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ws.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 03:25:05 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/28 17:00:01 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <ctype.h>

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

t_DATA			*display_ws(t_DATA *DATA)
{
	wchar_t		*s;
	size_t		i;
	int			len;

	i = 0;
	len = 0;
	s = (wchar_t *)va_arg(DATA->args, wchar_t *);
	if (DATA->precision > -1 && s)
		s = wstrndup(s, DATA->precision);
	else if (DATA->precision == -1 && s)
		s = wstrdup(s);
	else if (DATA->precision > -1 && !s)
		s = wstrndup(L"(null)", DATA->precision);
	else if (DATA->precision == -1&& !s)
		s = wstrdup(L"(null)");
	while (s[i])
		len += char_len(s[i++]);
	if (DATA->converter_flag[0] != '-')
		display_gap(DATA, ' ', DATA->field_width - len, 1);
	i = 0;
	while (s[i])
		display_wchar(s[i++], DATA);
	if (DATA->converter_flag[0] == '-')
		display_gap(DATA, ' ', DATA->field_width - len, 1);
	free (s);
	return (DATA);
}
