/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:23:31 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/29 09:24:09 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstclear(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*temp;

	if (!lst || !(*lst) || !del)
		return ;
	while ((*lst)->next)
	{
		temp = (*lst)->next;
		ft_dlstdelone(*lst, del);
		*lst = temp;
	}
	ft_dlstdelone(*lst, del);
	*lst = NULL;
}
