/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:16:52 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/18 14:04:17 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_for_enemies(t_data *data)
{
	size_t	i;
	t_pos	*pos;

	if (!data->maps[data->i].nbr_foes)
		return ;
	i = -1;
	pos = &(data->maps[data->i].player);
	while (++i < data->maps[data->i].nbr_foes)
		if (pos->x == data->maps[data->i].foes[i].x && \
		pos->y == data->maps[data->i].foes[i].y)
			end_game(message(GAME_OVER), data);
}

void	move_character(t_data *data, t_pos pos, size_t x, size_t y)
{
	t_map	*map;

	map = &(data->maps[data->i]);
	render_character(data);
	if (!(map->nbr_coins) && map->map[y][x] == 'E')
		next_map(data);
	else if (map->map[y][x] != '1')
	{
		map->player.x = x;
		map->player.y = y;
		map->player.moves++;
		render_character(data);
		update_counter(data);
		render_tile(data, pos.x, pos.y);
		if (map->map[y][x] == 'C' && map->nbr_coins--)
		{
			map->map[y][x] = '0';
			if (!(map->nbr_coins))
				put_image(data, TRAP_O, map->exit.x, map->exit.y);
		}
		check_for_enemies(data);
		move_foes(data);
		check_for_enemies(data);
	}
}

void	render_character(t_data *data)
{
	t_map	*map;

	map = &(data->maps[data->i]);
	if (map->map[map->player.y][map->player.x] == 'E' && map->nbr_coins)
		put_image(data, LOST_TD + map->player.dir, \
		map->player.x, map->player.y);
	else if (map->map[map->player.y][map->player.x] == 'C')
		put_image(data, LOST_ITEM, map->player.x, map->player.y);
	else
		put_image(data, LOST_FD + map->player.dir, \
		map->player.x, map->player.y);
}
