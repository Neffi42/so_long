/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_level.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:30:28 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/15 09:19:02 by abasdere         ###   ########.fr       */
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

static void	render_walls(t_data *data)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y < data->maps[data->i].height)
	{
		x = -1;
		if (!y)
			while (++x < data->maps[data->i].width - 1)
				put_image(data, 8, x, y);
		else if (y + 1 == data->maps[data->i].height)
			while (++x < data->maps[data->i].width - 1)
				put_image(data, 10, x, y);
		else
		{
			put_image(data, 9, 0, y);
			put_image(data, 11, data->maps[data->i].width - 1, y);
		}
	}
}

static void	render_rocks(t_data *data)
{
	size_t	y;
	size_t	x;
	int		r;

	y = 0;
	while (++y < data->maps[data->i].height - 1)
	{
		x = 0;
		while (++x < data->maps[data->i].width - 1)
		{
			if (data->maps[data->i].map[y][x] == '1')
			{
				r = ft_rand() % 8;
				if (r < 0)
					r = -r;
				put_image(data, 14 + r, x, y);
			}
		}
	}

}

void	render_level(t_data *data)
{
	render_floor(data);
	render_walls(data);
	render_corners(data);
	render_rocks(data);
}
