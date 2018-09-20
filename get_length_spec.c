/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length_spec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 09:46:33 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/08/11 09:51:38 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_length_spec(char **format, char *opt)
{
	while (**format && ft_strindex("hljz", **format) != -1)
	{
		if (**format == *(*format + 1) || *(*format + 1) == 'h')
		{
			if (**format == 'h' || **format == 'l')
				opt[3] = **format - 32;
			else
				opt[3] = 'L';
			(*format)++;
		}
		else
			opt[3] = **format;
		(*format)++;
	}
}
