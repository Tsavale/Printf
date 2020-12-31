/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsavale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:02:59 by tsavale           #+#    #+#             */
/*   Updated: 2019/10/24 14:28:24 by tsavale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t max;

	if (*needle == '\0')
		return ((char *)haystack);
	max = ft_strlen(needle);
	while ((*haystack != '\0') && (max <= len))
	{
		if ((*haystack == *needle) && (ft_memcmp(haystack, needle, max) == 0))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
