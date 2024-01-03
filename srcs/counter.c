/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:55:16 by abasdere          #+#    #+#             */
/*   Updated: 2024/01/03 11:33:25 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_counter(t_data *data)
{
	t_map	*map;
	size_t	i;
	char	*nbr;

	map = &(data->maps[data->i]);
	i = -1;
	if (map->player.moves >= 10000)
		(message(ERROR_MOVES), end_game(message(GAME_OVER), data));
	if (data->bonus)
	{
		nbr = ft_itoa(map->player.moves);
		if (!nbr)
			end_game(error(-1, ERROR_MALLOC, NULL), data);
		while (nbr[++i])
			put_image(data, DIGIT_0 + nbr[i] - '0', 1 + i, -1);
		free(nbr);
	}
	else
		ft_printf("moves: %d\n", map->player.moves);
}

void	render_counter(t_data *data)
{
	if (data->bonus)
		(put_image(data, MOVE, -1, -1), put_image(data, SEMI_COL, 0, -1), \
		update_counter(data));
	else
		ft_printf("moves: %d\n", data->maps[data->i].player.moves);
}
