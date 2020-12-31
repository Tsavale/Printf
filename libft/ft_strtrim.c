/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsavale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:23:59 by tsavale           #+#    #+#             */
/*   Updated: 2019/10/22 17:02:35 by tsavale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static	int		ft_check(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (0);
		i++;
	}
	return (1);
}

static	int		ft_len(char const *s1, char const *set)
{
	size_t	i;
	size_t	count;

	i = ft_strlen(s1) - 1;
	count = 0;
	while (ft_check(s1[count], set) == 0)
		count++;
	if (count == ft_strlen(s1))
		return (-1);
	while (ft_check(s1[i], set) == 0)
	{
		i--;
		count++;
	}
	return (count);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	size_t		len;
	char		*cpy;

	i = 0;
	j = 0;
	if (!s1 && set)
		return (NULL);
	if (s1 && !set)
		return (ft_strdup(s1));
	if (!s1 && !set)
		return (NULL);
	len = ft_strlen(s1) - ft_len(s1, set);
	if (!(cpy = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (ft_len(s1, set) == -1)
		len = 0;
	while (ft_check(s1[i], set) == 0)
		i++;
	while (j < len)
		cpy[j++] = s1[i++];
	cpy[j] = '\0';
	return (cpy);
}
