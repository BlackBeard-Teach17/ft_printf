/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 12:50:11 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/08/11 12:23:10 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_conversions(va_list ap, char *opt, int *plen, t_char string)
{
	long long int	res;

	res = 0;
	if (opt[4] == '%')
		res = 1;
	else if (opt[4] == 'C' || (opt[3] == 'l' && opt[4] == 'c'))
		string.wchar = va_arg(ap, wchar_t);
	else if (opt[4] == 's' && opt[3] != 'l')
		string.str = va_arg(ap, const char *);
	else if (opt[4] == 'S' || (opt[3] == 'l' && opt[4] == 's'))
		string.wstr = va_arg(ap, wchar_t *);
	else if (opt[4] == 'c')
		string.c = va_arg(ap, int);
	else
		res = convert_nb(ap, opt[4], opt);
	if (res < 0 && ft_strindex("dDi", opt[4]) != -1 &&
			res != -9223372036854775807 - 1)
	{
		opt[2] = '-';
		res *= -1;
	}
	if (ft_strindex("pdDioOuUxX%", opt[4]) != -1)
		print_nbr(opt, plen, res);
	else
		print_str(opt, plen, string);
}

long long int	convert_nb(va_list ap, char c, char *opt)
{
	long long int	res;

	if (opt[3] || ft_strindex("DIOU", opt[4]) != -1)
	{
		if (ft_strindex("oOuUxX", c) != -1)
			res = convert_unsigned_int(ap, opt[3], opt[4]);
		else
			res = convert_int(ap, opt[3], opt[4]);
	}
	else
	{
		if (ft_strindex("di", c) != -1)
			res = va_arg(ap, int);
		else if (ft_strindex("ouxX", c) != -1)
			res = va_arg(ap, unsigned int);
		else
			res = va_arg(ap, long long);
	}
	return (res);
}
