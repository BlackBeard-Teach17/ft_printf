/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 10:10:13 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/08/11 10:11:03 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_nbr(char *opt, int *plen, long long int nbr)
{
	int	maxnbr;

	if (!nbr && opt[4] != 'o' && opt[4] != 'O')
		opt[0] = 0;
	if (!nbr && plen[1] == -1 && opt[4] == 'o' && opt[0] == '#')
		plen[1] = 0;
	maxnbr = get_maxnbrlen(nbr, opt, plen);
	plen[3] += BIGGER(maxnbr, BIGGER(plen[0], plen[1]));
	print_opt(opt, plen, maxnbr, nbr);
	if (plen[2] == 16 && opt[4] == 'X')
		plen[2] = 1;
	if (opt[4] == '%')
		write(1, "%", 1);
	if ((nbr || plen[1]) && opt[4] != '%')
		print_base(plen[2], nbr, opt);
	if (opt[1] == '-' && plen[0] > plen[1])
		ft_putnchar(' ', plen[0] - maxnbr);
}
