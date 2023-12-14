/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:39:37 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/14 11:22:15 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	find_el(t_map *map, char *l, char el)
{
	size_t	i;

	i = ft_count_char(l, el);
	if (i && el == 'P' && \
		init_pos(&(map->player), ft_strchr(l, el) - l, map->height - 1))
		map->nbr_player += i;
	else if (i && el == 'E' && \
		init_pos(&(map->exit), ft_strchr(l, el) - l, map->height - 1))
		map->nbr_exit += i;
	else if (i && el == 'C')
		map->nbr_coins += i;
	return (i);
}

void	find_all_chars(t_data *data, t_map *map, char *l, size_t len)
{
	size_t	i;

	i = find_el(map, l, 'P');
	i += find_el(map, l, 'E');
	i += find_el(map, l, 'C');
	i += find_el(map, l, '0');
	i += find_el(map, l, '1');
	if (i + 1!= len)
		end_game(error(-4, ERROR_WRONG_CHAR, map->map_file), data);
}
