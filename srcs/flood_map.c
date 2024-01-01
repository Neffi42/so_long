/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:44:23 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/19 10:12:06 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_flooded_map(t_fmap *fmap, t_map *map, int bonus)
{
	size_t	i;

	i = -1;
	fmap->bonus = bonus;
	fmap->nbr_coins = 0;
	fmap->nbr_exit = 0;
	fmap->map = ft_calloc(map->height + 1, sizeof(char *));
	if (!fmap->map)
		return (0);
	while (++i < map->height)
	{
		fmap->map[i] = ft_strdup(map->map[i]);
		if (!(fmap->map[i]))
			return ((void)ft_free_tab(fmap->map), 0);
	}
	return (1);
}

static void	flood(t_map *map, t_fmap *fmap, size_t x, size_t y)
{
	if (fmap->map[y][x] == '1' || (fmap->bonus && fmap->map[y][x] == 'X'))
		return ;
	else if (map->map[y][x] == 'E')
		++(fmap->nbr_exit);
	else if (map->map[y][x] == 'C')
		++(fmap->nbr_coins);
	fmap->map[y][x] = '1';
	if (y - 1 > 0 && fmap->map[y - 1][x] != '1')
		flood(map, fmap, x, y - 1);
	if (y + 1 < map->height && fmap->map[y + 1][x] != '1')
		flood(map, fmap, x, y + 1);
	if (x - 1 > 0 && fmap->map[y][x - 1] != '1')
		flood(map, fmap, x - 1, y);
	if (x + 1 < map->width && fmap->map[y][x + 1] != '1')
		flood(map, fmap, x + 1, y);
}

int	flood_map(t_map *map, int bonus)
{
	t_fmap	fmap;

	if (!init_flooded_map(&fmap, map, bonus))
		return (0);
	flood(map, &fmap, map->player.x, map->player.y);
	if (fmap.nbr_coins != map->nbr_coins || fmap.nbr_exit != map->nbr_exit)
		return ((void)ft_free_tab(fmap.map), 0);
	return ((void)ft_free_tab(fmap.map), 1);
}
