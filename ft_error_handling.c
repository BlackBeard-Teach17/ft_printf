/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:59:11 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/08/11 10:08:23 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	error_handle(char *opt)
{
	if (ft_strindex("uU", opt[4]) != -1 && opt[2])
		opt[2] = 0;
	if (opt[2] && opt[4] == 'p')
		opt[2] = 0;
	if (opt[2] && (opt[4] == 'o' || opt[4] == 'x' ||
				opt[4] == 'O' || opt[4] == 'X'))
		opt[2] = 0;
}

void	error_duplicate(char **format, char *opt, int *plen)
{
	while (ft_strindex(".#0+ ", *(*format)) != -1)
	{
		if (!opt[0] || !opt[1] || !opt[2])
			get_flags(format, opt);
		else if (**format == '+')
		{
			opt[2] = '+';
			(*format)++;
		}
		else
			(*format)++;
	}
	if (opt[0] == '#' && opt[1] == '-' && opt[2] == '+')
		plen[1] = 0;
}
