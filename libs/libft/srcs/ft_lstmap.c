/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:07:20 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/29 09:28:09 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;

	if (!lst)
		return (NULL);
	new = NULL;
	while (lst->next)
	{
		ft_lstadd_back(&new, ft_lstnew(f(lst->content)));
		if (!ft_lstlast(new))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		lst = lst->next;
	}
	ft_lstadd_back(&new, ft_lstnew(f(lst->content)));
	if (!ft_lstlast(new))
	{
		ft_lstclear(&new, del);
		return (NULL);
	}
	return (new);
}
