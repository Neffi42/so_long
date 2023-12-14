/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:25:54 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/14 16:26:09 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data *data, size_t i, size_t x, size_t y)
{
	t_vec	vec;

	vec = translation(0, 0, TILE_LEN, TILE_LEN);
	mlx_put_image_to_window(data->mlx, data->win, data->imgs[i].img, \
	x * TILE_LEN + vec.x, y * TILE_LEN + vec.y);
}
