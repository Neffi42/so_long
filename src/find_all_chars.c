/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:39:37 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/18 11:33:41 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	find_el(t_data *data, t_map *map, size_t height, char el)
{
	size_t	i;

	i = ft_count_char(map->map[height], el);
	if (i && el == 'P' && \
		init_pos(&(map->player), ft_strchr(map->map[height], el) \
		- map->map[height], height))
		map->nbr_player += i;
	else if (i && el == 'E' && \
		init_pos(&(map->exit), ft_strchr(map->map[height], el) \
		- map->map[height], height))
		map->nbr_exit += i;
	else if (i && el == 'C')
		map->nbr_coins += i;
	else if (data->bonus && i && el == 'X')
		map->nbr_foes += i;
	return (i);
}

void	find_all_chars(t_data *data, t_map *map, size_t height, size_t len)
{
	size_t	i;

	i = find_el(data, map, height, 'P');
	i += find_el(data, map, height, 'E');
	i += find_el(data, map, height, 'C');
	i += find_el(data, map, height, '0');
	i += find_el(data, map, height, '1');
	if (data->bonus)
		i += find_el(data, map, height, 'X');
	if (i != len)
		end_game(error(-4, ERROR_WRONG_CHAR, map->map_file), data);
}
