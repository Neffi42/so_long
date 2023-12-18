/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foes_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:44:05 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/18 15:14:22 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_pos_foe(t_map *map)
{
	size_t	i;
	size_t	x;
	size_t	y;

	i = 0;
	y = -1;
	while (i < map->nbr_foes && ++y < map->height)
	{
		x = -1;
		while (++x < map->width)
			if (map->map[y][x] == 'X')
				init_pos(&(map->foes[i++]), x, y);
	}
}

void	render_foes(t_data *data)
{
	size_t		i;
	int			x;
	t_timespec	s;
	t_map		*map;

	i = 0;
	x = -1;
	s.tv_sec = 0;
	s.tv_nsec = 175000000;
	map = &(data->maps[data->i]);
	init_pos_foe(map);
	while (++x + GOBLIN_B1 <= GOBLIN_R)
	{
		i = -1;
		while (++i < map->nbr_foes)
			put_image(data, GOBLIN_B1 + x, map->foes[i].x, \
			map->foes[i].y);
		nanosleep(&s, NULL);
	}
}

void	move_foes(t_data *data)
{
	t_map		*map;
	t_pos		pos;
	size_t		i;

	map = &(data->maps[data->i]);
	i = -1;
	while (++i < map->nbr_foes)
	{
		pos = pathfinder(data, map->player, map->foes[i]);
		render_tile(data, map->foes[i].x, map->foes[i].y);
		put_image(data, GOBLIN_R + pos.dir, pos.x, pos.y);
		map->foes[i] = pos;
	}
}
