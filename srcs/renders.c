/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:25:54 by abasdere          #+#    #+#             */
/*   Updated: 2024/01/03 12:50:54 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_data *data, size_t x, size_t y)
{
	t_map	*map;

	map = &(data->maps[data->i]);
	if (map->map[y][x] == 'E' && map->nbr_coins)
		put_image(data, TRAP_C, x, y);
	else
		put_image(data, FLOOR1 + (x + y) % 4, x, y);
}

t_vec	translation(int x, int y, int dest_x, int dest_y)
{
	t_vec	vec;

	vec.x = dest_x - x;
	vec.y = dest_y - y;
	return (vec);
}

void	put_image(t_data *data, size_t i, size_t x, size_t y)
{
	t_vec	vec;

	vec = translation(0, 0, TILE_LEN, TILE_LEN);
	mlx_put_image_to_window(data->mlx, data->win, data->imgs[i].img, \
	x * TILE_LEN + vec.x, y * TILE_LEN + vec.y);
}
