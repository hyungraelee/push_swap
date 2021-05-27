/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:17:43 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/27 21:17:44 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char	*dp;
	unsigned char	*sp;
	size_t			i;

	if (!dest && !src)
		return (0);
	dp = (unsigned char *)dest;
	sp = (unsigned char *)src;
	i = 0;
	while (i++ < size)
		*dp++ = *sp++;
	return (dest);
}
