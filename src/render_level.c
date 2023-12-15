/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_level.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:30:28 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/15 10:57:50 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_floor(t_data *data)
{
	size_t	y;
	size_t	x;
	int		r;

	y = -1;
	while (++y < data->maps[data->i].height)
	{
		x = -1;
		while (++x < data->maps[data->i].width)
		{
			r = ft_rand() % 4;
			if (r < 0)
				r = -r;
			put_image(data, r, x, y);
		}
	}
	put_image(data, 12, data->maps[data->i].exit.x, data->maps[data->i].exit.y);
}

static void	render_corners(t_data *data)
{
	put_image(data, 4, 0, 0);
	put_image(data, 5, 0, data->maps[data->i].height - 1);
	put_image(data, 6, data->maps[data->i].width - 1, 0);
	put_image(data, 7, data->maps[data->i].width - 1, \
	data->maps[data->i].height - 1);
}

static void	render_rocks_and_coins(t_data *data, size_t x, size_t y, int coins)
{
	int				r;

	r = 0;
	if (!coins)
		r = ft_rand() % 8;
	if (r < 0)
		r = -r;
	put_image(data, 14 + coins + r, x, y);
}

static void	render_walls_rocks_coins(t_data *data)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y < data->maps[data->i].height)
	{
		x = -1;
		while (++x < data->maps[data->i].width)
		{
			if (!y)
				put_image(data, 8, x, y);
			else if (y == data->maps[data->i].height - 1)
				put_image(data, 10, x, y);
			else if (!x)
				put_image(data, 9, 0, y);
			else if (x == data->maps[data->i].width - 1)
				put_image(data, 11, data->maps[data->i].width - 1, y);
			else if (data->maps[data->i].map[y][x] == '1')
				render_rocks_and_coins(data, x, y, 0);
			else if (data->maps[data->i].map[y][x] == 'C')
				render_rocks_and_coins(data, x, y, 8);
		}
	}
}

void	render_level(t_data *data)
{
	render_floor(data);
	render_walls_rocks_coins(data);
	render_corners(data);
}
