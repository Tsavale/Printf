/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsavale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:57:27 by tsavale           #+#    #+#             */
/*   Updated: 2019/10/24 14:11:12 by tsavale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!src || !dst)
		return (0);
	while (src[j] && j < dstsize - 1 && dstsize > 0)
	{
		dst[j] = src[j];
		j++;
	}
	if (dstsize - j > 0)
		dst[j] = '\0';
	while (src[i])
		i++;
	return (i);
}
