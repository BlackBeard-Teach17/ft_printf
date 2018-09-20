/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:22:49 by nhuber            #+#    #+#             */
/*   Updated: 2018/08/09 15:25:40 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		basing(long long int nb, int base)
{
	char	b;

	b = (base < 0) ? 'A' : 'a';
	base *= (base < 0) ? -1 : 1;
	nb %= base;
	if (nb < 10)
		return (nb + '0');
	nb %= 10;
	return (b + nb);
}

char			*ft_itoa_base(long long int value, int base)
{
	char	*res;
	int		sign;
	int		size;
	int		i;

	sign = 0;
	if (value == 0)
		return (ft_strdup("0"));
	if (value < 0)
		sign += (base == 10) ? 1 : 0;
	size = nbrlen(value, base);
	if (!(res = (char *)ft_memalloc(size + sign + 1)))
		return (NULL);
	i = size + sign - 1;
	while (value != 0)
	{
		res[i] = basing(value, base);
		value /= (base < 0) ? -base : base;
		i--;
	}
	res[i] = (sign == 1) ? '-' : res[i];
	res[size] = '\0';
	return (res);
}
