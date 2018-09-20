/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxnbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 15:35:34 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/08/09 15:37:53 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_maxnbrlen(long long int nbr, char *opt, int *plen)
{
	int		maxnbr;
	int		len;

	len = (nbr < 0) ? 1 : 0;
	set_base(opt, plen);
	if (ft_strindex("dDi", opt[4]) != -1)
		len += nbrlen(nbr, plen[2]);
	else
		len = unblen((unsigned long long)nbr, plen[2]);
	maxnbr = (len > plen[1]) ? len : plen[1];
	if (maxnbr == plen[1] && !plen[0] && (opt[4] == 'o' || opt[4] == 'O'))
		maxnbr--;
	if ((opt[0] == '#' && (opt[4] == 'o' || opt[4] == 'O')) ||
			(opt[2] && opt[4] != '%'))
		maxnbr++;
	if ((opt[0] == '#' && (opt[4] == 'x' || opt[4] == 'X')) || opt[4] == 'p')
		maxnbr += 2;
	if (!nbr && !plen[1])
		maxnbr--;
	return (maxnbr);
}
