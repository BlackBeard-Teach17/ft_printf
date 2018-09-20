/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 16:53:48 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/08/11 15:39:31 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	convert_int(va_list ap, char mod, char opt)
{
	long long int	res;

	res = 0;
	if (mod == 'H')
	{
		if (opt == 'D')
			res = va_arg(ap, unsigned long);
		else
		{
			res = va_arg(ap, int);
			if (res != 65535)
				res = (signed char)res;
		}
	}
	else if (mod == 'l' || ft_isupper(opt))
		res = va_arg(ap, long);
	else if (mod == 'h')
		res = (short)va_arg(ap, int);
	else if (mod == 'L')
		res = va_arg(ap, long long);
	else if (mod == 'j')
		res = va_arg(ap, uintmax_t);
	else if (mod == 'z')
		res = va_arg(ap, ssize_t);
	return (res);
}
