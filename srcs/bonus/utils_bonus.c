/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:59:01 by abasdere          #+#    #+#             */
/*   Updated: 2024/01/03 12:56:52 by abasdere         ###   ########.fr       */
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
	t_map		*map;

	i = 0;
	x = -1;
	map = &(data->maps[data->i]);
	init_pos_foe(map);
	while (++x + GOBLIN_B1 <= GOBLIN_R)
	{
		i = -1;
		while (++i < map->nbr_foes)
			put_image(data, GOBLIN_B1 + x, map->foes[i].x, \
			map->foes[i].y);
		wait_anim(1);
	}
}

void	wait_anim(int mul)
{
	t_timespec	s;

	s.tv_sec = 0;
	s.tv_nsec = ANIM_TIME * mul;
	nanosleep(&s, NULL);
}

void	check_for_foes(t_data *data)
{
	size_t	i;
	t_pos	*pos;

	if (!data->maps[data->i].nbr_foes)
		return ;
	i = -1;
	pos = &(data->maps[data->i].player);
	while (++i < data->maps[data->i].nbr_foes)
	{
		if (pos->x == data->maps[data->i].foes[i].x && \
		pos->y == data->maps[data->i].foes[i].y)
		{
			data->bonus = 2;
			put_image(data, LOST_D, pos->x, pos->y);
			message(CONTINUE);
		}
	}
}
