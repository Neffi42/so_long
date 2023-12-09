/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:44:23 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/09 09:44:35 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_flooded_map(t_fmap *fmap, float x, float y)
{
	fmap->nbr_coins = 0;
	fmap->nbr_exit = 0;
	fmap->nbr_player = 0;
	init_pos(&(fmap->last), x, y);
}

static void	parse_map(t_map *map, t_fmap *fmap, float x, float y)
{
	float	last_x;
	float	last_y;

	if (x < 0 || x > map->width - 1 || y < 0 || y > map->height - 1 \
		|| map->map[(int)y][(int)x] == '1')
		return ;
	else if (map->map[(int)y][(int)x] == 'P')
		fmap->nbr_player++;
	else if (map->map[(int)y][(int)x] == 'E')
		fmap->nbr_exit++;
	else if (map->map[(int)y][(int)x] == 'C')
		fmap->nbr_coins++;
	last_x = fmap->last.x;
	last_y = fmap->last.y;
	if (y > 0 && y - 1 != last_y && init_pos(&(fmap->last), x, y))
		parse_map(map, fmap, y - 1, x);
	if (y < map->height - 1 && y + 1 != last_y && init_pos(&(fmap->last), x, y))
		parse_map(map, fmap, y + 1, x);
	if (x > 0 && x - 1 != last_x && init_pos(&(fmap->last), x, y))
		parse_map(map, fmap, y, x - 1);
	if (x < map->width - 1 && x + 1 != last_x && init_pos(&(fmap->last), x, y))
		parse_map(map, fmap, y + 1, x + 1);
}

int	flood_map(t_map *map)
{
	t_fmap	fmap;
	size_t	i;

	init_flooded_map(&fmap, map->player.x, map->player.y);
	i = -1;
	while (map->map[++i])
		ft_dprintf(1, "%s\n", map->map[i]);
	parse_map(map, &fmap, -1, -1);
	if (fmap.nbr_coins != map->nbr_coins || fmap.nbr_exit != map->nbr_exit \
		|| fmap.nbr_player != map->nbr_player)
		return (0);
	return (1);
}
