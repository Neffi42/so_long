/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_level.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:30:28 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/14 15:16:45 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_floor(t_data *data, t_vec vec)
{
	size_t	i;
	size_t	j;
	int		x;

	i = -1;
	vec = translation(0, 0, TILE_LEN, TILE_LEN);
	while (++i < data->maps[data->i].height)
	{
		j = -1;
		while (++j < data->maps[data->i].width)
		{
			x = ft_rand() % 4;
			if (x < 0)
				x = -x;
			mlx_put_image_to_window(data->mlx, data->win, \
			data->imgs[x].img, j * TILE_LEN + vec.x, i * TILE_LEN + vec.y);
		}
	}
}

static void	render_corners(t_data *data, t_vec vec)
{
	mlx_put_image_to_window(data->mlx, data->win, \
	data->imgs[4].img, vec.x, vec.y);
	mlx_put_image_to_window(data->mlx, data->win, data->imgs[5].img, \
	vec.x, (data->maps[data->i].height - 1) * TILE_LEN + vec.y);
	mlx_put_image_to_window(data->mlx, data->win, data->imgs[6].img, \
	(data->maps[data->i].width - 1) * TILE_LEN + vec.x, vec.y);
	mlx_put_image_to_window(data->mlx, data->win, data->imgs[7].img, \
	(data->maps[data->i].width - 1) * TILE_LEN + vec.x, \
	(data->maps[data->i].height - 1) * TILE_LEN + vec.y);
}

static void	render_walls(t_data *data, t_vec vec)
{
	(void)data;
	(void)vec;
}

void	render_level(t_data *data)
{
	t_vec	vec;

	vec = translation(0, 0, TILE_LEN, TILE_LEN);
	render_floor(data, vec);
	render_walls(data, vec);
	render_corners(data, vec);
}
