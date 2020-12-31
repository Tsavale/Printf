/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsavale <tsavale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 14:56:54 by tsavale           #+#    #+#             */
/*   Updated: 2020/12/31 16:02:51 by tsavale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_start_fl(t_fl *fl)
{
	fl->str = NULL;
	fl->cv = 0;
	fl->p = -1;
	fl->fw = 0;
	fl->zeros = 0;
}

int		ft_flag_fl(char *str, t_fl *fl)
{
	int	i;

	i = 0;
	while (ft_isflag(str[i]))
	{
		if (str[i] == '-')
			fl->fw = -1;
		if (str[i] == '0' && fl->fw != -1)
			fl->zeros = 1;
		if (fl->fw == -1)
			fl->zeros = 0;
		i++;
	}
	return (i);
}

int		ft_fw_fl(va_list *ap, char *str, t_fl *fl)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (str[i] == '*' || ft_isdigit(str[i]))
	{
		if (fl->fw != -1)
			sign = 1;
		else
			sign = -1;
		if (str[i] == '*')
			fl->fw = va_arg(*ap, int);
		else
			fl->fw = ft_atoi(str);
		fl->zeros *= fl->fw;
		i++;
	}
	else
		fl->fw = 0;
	if (fl->fw > 0)
		fl->fw *= sign;
	while (ft_isdigit(str[i]) && str[0] != '*')
		i++;
	return (i);
}

int		ft_precision_fl(va_list *ap, char *str, t_fl *fl)
{
	int	i;

	i = 0;
	if (str[i] == '*' || ft_isdigit(str[i]))
		fl->p = ((str[i++] == '*') ? va_arg(*ap, unsigned int) : ft_atoi(str));
	while (ft_isdigit(str[i]) && str[0] != '*')
		i++;
	return (i);
}
