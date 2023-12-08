/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:44:23 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/08 18:05:29 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_flooded_map(t_fmap *fmap)
{
	fmap->nbr_coins = 0;
	fmap->nbr_exit = 0;
	fmap->nbr_player = 0;
}

int	flood_map(t_map *map)
{
	t_fmap	fmap;
	size_t	i;

	init_flooded_map(&fmap);
	i = -1;
	while (map->map[++i])
		ft_dprintf(1, "%s\n", map->map[i]);
	ft_dprintf(1, "P: %d %d\nE: %d %d\n", map->player.x, map->player.y, \
		map->exit.x, map->exit.y);
	if (fmap.nbr_coins != map->nbr_coins || fmap.nbr_exit != map->nbr_exit \
		|| fmap.nbr_player != map->nbr_player)
		return (0);
	return (1);
}
