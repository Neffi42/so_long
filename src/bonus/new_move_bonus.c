/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_move_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:52:49 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/20 08:54:06 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	exit_level(t_data *data)
{
	data->bonus = 3;
	render_tile(data, data->maps[data->i].player.x, \
	data->maps[data->i].player.y);
	put_image(data, LOST_JUMP, data->maps[data->i].exit.x, \
	data->maps[data->i].exit.y);
	message(CONTINUE);
}

void	new_move(t_data *data, t_pos pos, size_t x, size_t y)
{
	int	i;

	i = move_character(data, pos, x, y);
	if (!i)
		exit_level(data);
	if (i == 1)
	{
		check_for_foes(data);
		move_foes(data);
		check_for_foes(data);
	}
}
