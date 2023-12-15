/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_level.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:30:28 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/15 15:09:41 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_floor(t_data *data, t_map *map)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
			render_tile(data, x, y);
	}
	put_image(data, TRAP_C, map->exit.x, map->exit.y);
}

static void	render_corners(t_data *data, t_map *map)
{
	put_image(data, CORNER_LU, 0, 0);
	put_image(data, CORNER_LD, 0, map->height - 1);
	put_image(data, CORNER_RU, map->width - 1, 0);
	put_image(data, CORNER_RD, map->width - 1, map->height - 1);
}

static void	render_rocks_and_coins(t_data *data, size_t x, size_t y, int coins)
{
	int		r;

	r = 0;
	if (!coins)
	{
		r = ft_rand() % 8;
		if (r < 0)
			r = -r;
	}
	put_image(data, ROCK1_1 + coins + r, x, y);
}

static void	render_walls_rocks_coins(t_data *data, t_map *map)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (!y)
				put_image(data, WALL_U, x, y);
			else if (y == map->height - 1)
				put_image(data, WALL_D, x, y);
			else if (!x)
				put_image(data, WALL_L, 0, y);
			else if (x == map->width - 1)
				put_image(data, WALL_R, map->width - 1, y);
			else if (map->map[y][x] == '1')
				render_rocks_and_coins(data, x, y, 0);
			else if (map->map[y][x] == 'C')
				render_rocks_and_coins(data, x, y, 8);
		}
	}
}

void	render_level(t_data *data)
{
	render_floor(data, &(data->maps[data->i]));
	render_walls_rocks_coins(data, &(data->maps[data->i]));
	render_corners(data, &(data->maps[data->i]));
}
