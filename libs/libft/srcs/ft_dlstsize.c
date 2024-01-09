/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:20:09 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/29 09:21:21 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dlstsize(t_dlist *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (i);
	i++;
	while (lst->next)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
