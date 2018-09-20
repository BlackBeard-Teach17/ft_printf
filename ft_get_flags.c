/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 15:57:49 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/08/10 17:14:49 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flags(char **format, char *opt)
{
	while (**format && ft_strindex("#+- 0", **format) != -1)
	{
		if (**format == '#' && !opt[0])
			opt[0] = '#';
		if (**format == '0' && opt[1] != '-')
			opt[1] = **format;
		if (**format == '-')
			opt[1] = **format;
		if (**format == ' ' && !opt[2])
			opt[2] = **format;
		if (**format == '+')
			opt[2] = **format;
		(*format)++;
	}
}
