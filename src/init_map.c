/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:01:44 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/08 12:26:39 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *map)
{
	map->nbr_coins = 0;
	map->coins = NULL;
	map->nbr_exit = 0;
	init_pos(&map->exit, -1, -1);
	map->nbr_player = 0;
	init_pos(&map->player, -1, -1);
	map->height = 1;
	map->width = 0;
	map->is_rectangle = 0;
	map->map = NULL;
}
