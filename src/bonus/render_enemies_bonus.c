/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemies_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:44:05 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/17 15:35:18 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_pos_free(t_pos *pos_e, t_map	*map, t_pos pos, size_t i)
{
	size_t	j;

	j = -1;
	if (map->map[pos.y][pos.x] == '1' || map->map[pos.y][pos.x] == 'E' || \
		map->map[pos.y][pos.x] == 'P')
		return (0);
	while (++j < i)
		if (pos_e[j].x == pos.x && pos_e[j].y == pos.y)
			return (0);
	return (1);
}

static t_pos	rand_pos_enemy(t_data *data, size_t i)
{
	t_map	*map;
	t_pos	pos;

	map = &(data->maps[data->i]);
	pos.x = ft_range_rand(map->width);
	pos.y = ft_range_rand(map->height);
	while (!is_pos_free(data->pos_e, map, pos, i))
	{
		pos.x = ft_range_rand(map->width);
		pos.y = ft_range_rand(map->height);
	}
	return (pos);
}

void	render_enemies(t_data *data)
{
	size_t		i;
	int			x;
	t_timespec	s;

	i = -1;
	x = -1;
	s.tv_sec = 0;
	s.tv_nsec = 175000000;
	data->nbr_e = ft_range_rand(data->maps[data->i].nbr_coins) / 2;
	data->pos_e = ft_calloc(++(data->nbr_e), sizeof(t_pos));
	if (!data->pos_e)
		end_game(error(-1, ERROR_MALLOC, NULL), data);
	while (++i < data->nbr_e)
		data->pos_e[i] = rand_pos_enemy(data, i);
	while (++x + GOBLIN_B1 <= GOBLIN_R)
	{
		i = -1;
		while (++i < data->nbr_e)
			put_image(data, GOBLIN_B1 + x, data->pos_e[i].x, \
			data->pos_e[i].y);
		nanosleep(&s, NULL);
	}
}
