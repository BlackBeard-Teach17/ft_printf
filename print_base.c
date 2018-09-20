/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 10:11:30 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/08/11 10:12:51 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_base(int base, long long int nbr, char *opt)
{
	char	*out;

	if (base == 1)
		base = -16;
	if (ft_strindex("dDi", opt[4]) != -1)
		out = (nbr == -9223372036854775807 - 1) ?
			ft_strdup("-9223372036854775808") : ft_itoa_base(nbr, base);
	else
		out = ft_uitoa_base((unsigned long long int)nbr, base);
	ft_putnstr(out, ft_strlen(out));
	ft_memdel((void *)&out);
}
