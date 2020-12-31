/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsavale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:28:32 by tsavale           #+#    #+#             */
/*   Updated: 2019/10/24 13:34:17 by tsavale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *new;

	if (!lst)
		lst = NULL;
	if (f)
	{
		while (lst)
		{
			new = lst->next;
			f((lst)->content);
			lst = new;
		}
	}
}
