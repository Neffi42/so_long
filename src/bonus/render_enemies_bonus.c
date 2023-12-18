/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemies_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:44:05 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/18 11:19:37 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_pos_free(t_pos *pos_foes, t_map	*map, t_pos pos, size_t i)
{
	size_t	j;

	j = -1;
	if (map->map[pos.y][pos.x] == '1' || map->map[pos.y][pos.x] == 'E' || \
		map->map[pos.y][pos.x] == 'P' || map->map[pos.y][pos.x] == 'C')
		return (0);
	while (++j < i)
		if (pos_foes[j].x == pos.x && pos_foes[j].y == pos.y)
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
	while (!is_pos_free(map->pos_foes, map, pos, i))
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
	t_map		*map;

	i = -1;
	x = -1;
	s.tv_sec = 0;
	s.tv_nsec = 175000000;
	map = &(data->maps[data->i]);
	map->pos_foes = ft_calloc(map->nbr_foes, sizeof(t_pos));
	if (!map->pos_foes)
		end_game(error(-1, ERROR_MALLOC, NULL), data);
	while (++i < map->nbr_foes)
		map->pos_foes[i] = rand_pos_enemy(data, i);
	while (++x + GOBLIN_B1 <= GOBLIN_R)
	{
		i = -1;
		while (++i < map->nbr_foes)
			put_image(data, GOBLIN_B1 + x, map->pos_foes[i].x, \
			map->pos_foes[i].y);
		nanosleep(&s, NULL);
	}
}
