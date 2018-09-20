/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 08:47:52 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/08/11 11:59:48 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_tags(char **format, char *opt, int *plen)
{
	(*format)++;
	get_flags(format, opt);
	if (ft_isdigit(**format))
	{
		plen[0] = ft_atoi(*format);
		*format += nbrlen(plen[0], 10);
	}
	get_precision(format, plen);
	get_length_spec(format, opt);
	error_duplicate(format, opt, plen);
	opt[4] = **format;
	error_handle(opt);
}

void	get_precision(char **format, int *plen)
{
	if (**format == '.')
	{
		while (**format == '.')
			(*format)++;
		if (ft_isdigit(*(*(format))))
		{
			plen[1] = ft_atoi(*(format));
			*format += nbrlen(plen[1], 10);
		}
	}
	else
		plen[1] = -1;
}
