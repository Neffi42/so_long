/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keypress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:47:19 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/19 14:14:32 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	set_dir(t_data *data, int dir)
{
	data->maps[data->i].player.dir = dir;
	return (1);
}

int	event_keypress(int keysym, t_data *data)
{
	t_pos	pos;

	pos = data->maps[data->i].player;
	if (keysym == XK_Escape)
		end_game(message(GAME_OVER), data);
	if ((keysym == XK_s || keysym == XK_Down) && set_dir(data, 0))
		move_character(data, pos, pos.x, pos.y + 1);
	if ((keysym == XK_a || keysym == XK_Left) && set_dir(data, 1))
		move_character(data, pos, pos.x - 1, pos.y);
	if ((keysym == XK_w || keysym == XK_Up) && set_dir(data, 2))
		move_character(data, pos, pos.x, pos.y - 1);
	if ((keysym == XK_d || keysym == XK_Right) && set_dir(data, 3))
		move_character(data, pos, pos.x + 1, pos.y);
	return (0);
}
