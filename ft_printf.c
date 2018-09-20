/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 09:10:06 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/08/09 09:58:47 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	int		plen[4];
	char	opt[5];
	va_list	va;
	t_char	string;

	va_start(va, format);
	plen[3] = 0;
	while (*format)
	{
		ft_printf_init(&format, opt, plen, &string);
		if (*format)
		{
			get_tags(&format, opt, plen);
			if (ft_strindex("sSpdDioOuUxXcC%", opt[4]) != -1)
			{
				format++;
				ft_conversions(va, opt, plen, string);
			}
			else
				set_undefined(&format, opt, plen, -7);
		}
	}
	va_end(va);
	return (plen[3]);
}

void	ft_printf_init(char **format, char *opt, int *plen, t_char *string)
{
	plen[3] += ft_strprintlen(*format, '%');
	(*format) += ft_strchrlen(*format, '%');
	set_params(plen, opt, string);
}
