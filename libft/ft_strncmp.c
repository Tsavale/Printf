/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsavale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:45:41 by tsavale           #+#    #+#             */
/*   Updated: 2019/10/22 13:46:08 by tsavale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n - 1 && s1[a] && s1[a] == s2[a])
		a++;
	if (n)
		return (*((unsigned char *)s1 + a) - *((unsigned char *)s2 + a));
	return (0);
}
