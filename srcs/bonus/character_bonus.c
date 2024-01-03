/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:16:52 by abasdere          #+#    #+#             */
/*   Updated: 2024/01/03 12:56:22 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	exit_level(t_data *data)
{
	data->bonus = 3;
	render_tile(data, data->maps[data->i].player.x, \
	data->maps[data->i].player.y);
	put_image(data, LOST_JUMP, data->maps[data->i].exit.x, \
	data->maps[data->i].exit.y);
	message(CONTINUE);
}

void	new_move(t_data *data, t_pos pos, size_t x, size_t y)
{
	int	i;

	i = move_character(data, pos, x, y);
	if (!i)
		exit_level(data);
	if (i == 1)
	{
		check_for_foes(data);
		move_foes(data);
		check_for_foes(data);
	}
}

int	move_character(t_data *data, t_pos pos, size_t x, size_t y)
{
	t_map	*map;

	map = &(data->maps[data->i]);
	render_character(data);
	if (!(map->nbr_coins) && map->map[y][x] == 'E')
		return (0);
	if (map->map[y][x] != '1')
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
		return (1);
	}
	return (-1);
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
