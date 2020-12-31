/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_symbole.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsavale <tsavale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 14:58:46 by tsavale           #+#    #+#             */
/*   Updated: 2020/12/31 14:58:51 by tsavale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isin(int c, char *set)
{
	while (set && *set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

int		ft_isaconversion(int c)
{
	if (ft_isin(c, "cspdiuxX%"))
		return (1);
	return (0);
}

int		ft_isflag(int c)
{
	if (ft_isin(c, " -0"))
		return (1);
	return (0);
}
