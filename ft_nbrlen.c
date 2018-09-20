/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 12:08:57 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/08/11 12:25:51 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nbrlen(long long int nb, int base)
{
	int length;

	length = 1;
	while ((nb /= base))
		++length;
	return (length);
}
