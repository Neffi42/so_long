/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:21:25 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/10 13:51:34 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_maps(t_map *maps)
{
	size_t	i;

	i = -1;
	if (!maps)
		return ;
	while (maps[++i].map != NULL)
	{
		free(maps[i].coins);
		ft_free_split(maps[i].map);
	}
	free(maps);
}
