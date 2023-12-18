/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:09:15 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/18 16:09:40 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*free_dmap(t_dmap **dmap)
{
	size_t	i;

	i = 0;
	while (dmap[i])
		free(dmap[i++]);
	free(dmap);
	return (NULL);
}
