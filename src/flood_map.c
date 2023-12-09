/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:44:23 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/09 18:53:26 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_flooded_map(t_fmap *fmap, t_map map, float x, float y)
{
	size_t	i;

	i = -1;
	fmap->nbr_coins = 0;
	fmap->nbr_exit = 0;
	fmap->nbr_player = 0;
	init_pos(&(fmap->last), x, y);
	fmap->map = ft_calloc(map.height + 1, sizeof(char *))
	if (!fmap->map)
		return (0);
	while (++i < map.height)
		fmap->map[i] = ft_strdup(map.map[i]);
	return (1);
}
// use flood map to fill it with 1 and stop flooding
static void	parse_map(t_map *map, t_fmap *fmap, float x, float y)
{
	float	last_x;
	float	last_y;

	if (x < 0 || x > map->width - 1 || y < 0 || y > map->height - 1 \
		|| map->map[(size_t)y][(size_t)x] == '1')
		return ;
	else if (map->map[(size_t)y][(size_t)x] == 'P' && ++(fmap->nbr_player))
		map->map[(size_t)y][(size_t)x] = '0';
	else if (map->map[(size_t)y][(size_t)x] == 'E' && ++(fmap->nbr_exit))
		map->map[(size_t)y][(size_t)x] = '0';
	else if (map->map[(size_t)y][(size_t)x] == 'C' && \
		init_pos(&map->coins[(fmap->nbr_coins)++], x, y))
		map->map[(size_t)y][(size_t)x] = '0';
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

	if (!init_flooded_map(&fmap, -1, -1));
		return (0);
	i = -1;
	while (map->map[++i])
		ft_dprintf(1, "%s\n", map->map[i]);
	parse_map(map, &fmap, map->player.x, map->player.y);
	printf("%ld %ld %ld %ld %ld %ld\n", fmap.nbr_coins, map->nbr_coins, fmap.nbr_exit, \
		map->nbr_exit, fmap.nbr_player, map->nbr_player);
	i = -1;
	while (map->map[++i])
		ft_dprintf(1, "%s\n", map->map[i]);
	if (fmap.nbr_coins != map->nbr_coins || fmap.nbr_exit != map->nbr_exit \
		|| fmap.nbr_player != map->nbr_player)
		return (0);
	return (1);
}
