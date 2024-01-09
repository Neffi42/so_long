/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:06:44 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/29 12:49:28 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
	t_dlist	*temp;

	temp = *lst;
	new->next = temp;
	new->prev = NULL;
	if (temp)
		temp->prev = new;
	*lst = new;
}
