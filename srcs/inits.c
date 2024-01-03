/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:54:18 by abasdere          #+#    #+#             */
/*   Updated: 2024/01/03 12:49:20 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *data, size_t len, int bonus)
{
	data->mlx = NULL;
	data->win = NULL;
	data->maps = NULL;
	data->imgs = NULL;
	data->i = 0;
	data->len = len;
	data->bonus = bonus;
}

void	init_map(t_map *map, const char *map_file)
{
	map->nbr_coins = 0;
	map->nbr_exit = 0;
	init_pos(&(map->exit), -1, -1);
	map->nbr_player = 0;
	init_pos(&(map->player), -1, -1);
	map->height = 1;
	map->width = 0;
	map->is_rectangle = 0;
	map->map = NULL;
	map->map_file = map_file;
	map->nbr_foes = 0;
	map->foes = NULL;
}

int	init_pos(t_pos *pos, size_t x, size_t y)
{
	pos->x = x;
	pos->y = y;
	pos->dir = 0;
	pos->moves = 0;
	return (1);
}

void	init_img(t_data *data, size_t i, char *path)
{
	data->imgs[i].img = mlx_xpm_file_to_image(data->mlx, path, \
	&data->imgs[i].width, &data->imgs[i].height);
	if (!data->imgs[i].img)
		end_game(error(-12, ERROR_IMG, path), data);
}
