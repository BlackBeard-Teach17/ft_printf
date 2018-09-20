/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 08:43:47 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/08/08 17:02:30 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Its very similar to ft_strlen except that because wide chars can be viriable
**	size, we can't just do len++ and must instead accumulate the sum of each
**	wide character in the wide string.
*/

int	ft_wstrlen(wchar_t *ws, int max)
{
	int	i;
	int	len;

	if (!ws)
		return (-1);
	i = 0;
	len = 0;
	if (max == -1)
		max = 2147483647;
	while (ws[i])
	{
		if (len + 1 <= max && ws[i] <= 0x7F)
			len += 1;
		else if (len + 2 <= max && ws[i] <= 0x7FF)
			len += 2;
		else if (len + 3 <= max && ws[i] <= 0xFFFF)
			len += 3;
		else if (len + 4 <= max)
			len += 4;
		i++;
	}
	return (len);
}
