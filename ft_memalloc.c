/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 10:19:07 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/08/08 16:57:53 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)) || size == 0)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
