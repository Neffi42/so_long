/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foes_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:44:05 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/19 14:09:00 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_pos_free(char **map, size_t x, size_t y)
{
	if (map[y][x] == '0')
		return (1);
	return (0);
}

static int	is_pos_player(char **map, t_pos *pos, t_pos foe, t_pos p)
{
	int	x;

	x = -1;
	if (p.y == foe.y && p.x == foe.x + 1 && init_pos(pos, foe.x + 1, foe.y))
		return (0);
	else if (is_pos_free(map, foe.x + 1, foe.y))
		x--;
	if (p.y == foe.y && p.x == foe.x - 1 && init_pos(pos, foe.x - 1, foe.y))
		return (1);
	else if (is_pos_free(map, foe.x - 1, foe.y))
		x--;
	if (p.y == foe.y + 1 && p.x == foe.x && init_pos(pos, foe.x, foe.y + 1))
		return (2);
	else if (is_pos_free(map, foe.x, foe.y + 1))
		x--;
	if (p.y == foe.y - 1 && p.x == foe.x && init_pos(pos, foe.x, foe.y - 1))
		return (3);
	else if (is_pos_free(map, foe.x, foe.y - 1))
		x--;
	return (x);
}

static int	init_from_dir(t_pos *pos, t_pos foe, int dir)
{
	if (!dir && init_pos(pos, foe.x + 1, foe.y))
		pos->dir = dir;
	if (dir == 1 && init_pos(pos, foe.x - 1, foe.y))
		pos->dir = dir;
	if (dir == 2 && init_pos(pos, foe.x, foe.y + 1))
		pos->dir = dir;
	if (dir == 3 && init_pos(pos, foe.x, foe.y - 1))
		pos->dir = dir;
	return (1);
}

static int	rand_pos(char **map, t_pos *pos, t_pos foe, t_pos p)
{
	int	r;

	r = is_pos_player(map, pos, foe, p);
	if (r == -1)
		return (0);
	if (r >= 0)
		return (pos->dir = r, 1);
	r = ft_range_rand(4);
	while (init_from_dir(pos, foe, r) && !is_pos_free(map, pos->x, pos->y))
		r = ft_range_rand(4);
	return (1);
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
		if (rand_pos(map->map, &pos, map->foes[i], map->player))
		{
			render_tile(data, map->foes[i].x, map->foes[i].y);
			put_image(data, GOBLIN_R + pos.dir, pos.x, pos.y);
			map->foes[i] = pos;
		}
	}
}
