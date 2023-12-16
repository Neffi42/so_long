/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemies_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:44:05 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/16 19:58:30 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check position with exit and player and other ennemies

static t_pos	rand_pos_enemy(t_data *data)
{
	t_map	*map;
	t_pos	pos;

	map = &(data->maps[data->i]);
	pos.x = ft_range_rand(map->width);
	pos.y = ft_range_rand(map->height);
	while ((pos.x == map->player.x && pos.y == map->player.y) || \
		(pos.x == map->exit.x && pos.y == map->exit.y))
	{
		pos.x = ft_range_rand(map->width);
		pos.y = ft_range_rand(map->height);
	}

	return (pos);
}

void	render_enemies(t_data *data)
{
	size_t	i;

	i = -1;
	data->nbr_e = ft_range_rand(data->maps[data->i].nbr_coins) / 2;
	data->pos_e = ft_calloc(++(data->nbr_e), sizeof(t_pos));
	if (data->pos_e)
		end_game(error(-1, ERROR_MALLOC, NULL), data);
	while (++i < data->nbr_e)
		data->pos_e[i] = rand_pos_enemy(data);
}
