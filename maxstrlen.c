/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxstrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 08:42:48 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/08/11 15:39:13 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_maxstrlen(t_char string, char *opt, int *plen)
{
	int	maxstr;

	maxstr = 0;
	if (opt[4] == 's' && !opt[3])
		maxstr = ft_strlen(string.str);
	else if (opt[4] == 'S' || (opt[3] == 'l' && opt[4] == 's'))
		maxstr = ft_wstrlen(string.wstr, plen[1]);
	else if (opt[4] == 'c' && !opt[3])
		maxstr = 1;
	else
		maxstr = ft_wcharlen(string.wchar);
	if (plen[1] >= 0 && opt[4] != 'c' && opt[4] != 'C')
		return (maxstr > plen[1] ? plen[1] : maxstr);
	else
		return (maxstr);
}
