/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unsigned_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 16:55:50 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/08/11 15:40:54 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	convert_unsigned_int(va_list ap, char mod, char opt)
{
	long long int	res;

	res = 0;
	if (mod == 'H')
	{
		res = va_arg(ap, unsigned int);
		if (res != 65535)
		{
			res = (unsigned char)res;
		}
	}
	else if (mod == 'l' || ft_isupper(opt))
		res = va_arg(ap, unsigned long);
	else if (mod == 'h')
		res = (unsigned short)va_arg(ap, unsigned int);
	else if (mod == 'L')
		res = va_arg(ap, unsigned long long);
	else if (mod == 'j')
		res = va_arg(ap, uintmax_t);
	else if (mod == 'z')
		res = va_arg(ap, size_t);
	return (res);
}
