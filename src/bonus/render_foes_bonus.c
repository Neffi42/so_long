/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_foes_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:27:50 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/19 10:45:09 by abasdere         ###   ########.fr       */
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
