/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsavale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:26:02 by tsavale           #+#    #+#             */
/*   Updated: 2019/10/24 14:26:11 by tsavale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			c;

	if (n == 0 || dst == src)
		return (dst);
	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	c = 0;
	while (n > c)
	{
		a[c] = b[c];
		c++;
	}
	return (dst);
}
