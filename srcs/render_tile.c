/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:32:00 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/16 15:19:18 by abasdere         ###   ########.fr       */
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
