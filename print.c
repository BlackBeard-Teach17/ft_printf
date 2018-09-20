/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 13:43:54 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/08/11 14:54:25 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_opt(char *opt, int *plen, int max, long long int nbr)
{
	if ((!opt[1] || (opt[1] == '0' && plen[1] >= 0)))
		ft_putnchar(' ', plen[0] - max);
	if (opt[2] && opt[4] != '%')
		write(1, &opt[2], 1);
	if ((opt[0] == '#'
				&& (opt[4] == 'X' || opt[4] == 'x')) || opt[4] == 'p')
		opt[4] == 'X' ? write(1, "0X", 2) : write(1, "0x", 2);
	if (opt[0] == '#' && (opt[4] == 'o' || opt[4] == 'O'))
	{
		write(1, "0", 1);
		plen[1] -= plen[1] > 0 ? 1 : 0;
	}
	if (opt[1] == '0' && plen[1] == -1)
		ft_putnchar('0', plen[0] - max);
	if (plen[1] > 0)
		ft_putnchar('0', plen[1] - nbrlen(nbr, plen[2]));
}
