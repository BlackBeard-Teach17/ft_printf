/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 10:09:14 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/08/11 10:09:58 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(char *opt, int *plen, t_char string)
{
	int	total;

	total = get_maxstrlen(string, opt, plen);
	if (opt[4] == 's' && plen[1] && !opt[3] && string.str == NULL)
		total = 6;
	set_undefined(NULL, opt, plen, total);
	if (opt[4] == 's' && !opt[3])
		total == 0 ? ft_putnstr(NULL, -1) : ft_putnstr(string.str, total);
	else if (opt[4] == 'c' && !opt[3])
		ft_putchar(string.c);
	else if (opt[4] == 'S' || (opt[3] == 'l' && opt[4] == 's'))
	{
		if (total == -1)
		{
			ft_putnstr("(null)", 6);
			total = 6;
		}
		else
			ft_putwstr(string.wstr, total);
	}
	else
		ft_putwchar(string.wchar);
	plen[3] += total > plen[0] ? total : plen[0];
	if (opt[1] == '-')
		ft_putnchar(' ', plen[0] - total);
}
