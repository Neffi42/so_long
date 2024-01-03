/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keypress_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:47:19 by abasdere          #+#    #+#             */
/*   Updated: 2024/01/03 11:52:19 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	set_dir(t_data *data, int dir)
{
	data->maps[data->i].player.dir = dir;
	return (1);
}

static int	set_bonus(t_data *data, int bonus)
{
	data->bonus = bonus;
	return (1);
}

int	event_keypress(int keysym, t_data *data)
{
	t_pos	pos;

	pos = data->maps[data->i].player;
	if (data->bonus < 0)
		return (0);
	if (data->bonus == 3)
		(set_bonus(data, -1), next_map(data));
	if (keysym == XK_Escape || (data->bonus == 2))
		(set_bonus(data, -1), end_game(message(GAME_OVER), data));
	if (data->bonus == 1 && (keysym == XK_s || keysym == XK_Down))
		(set_dir(data, 0), new_move(data, pos, pos.x, pos.y + 1));
	if (data->bonus == 1 && (keysym == XK_a || keysym == XK_Left))
		(set_dir(data, 1), new_move(data, pos, pos.x - 1, pos.y));
	if (data->bonus == 1 && (keysym == XK_w || keysym == XK_Up))
		(set_dir(data, 2), new_move(data, pos, pos.x, pos.y - 1));
	if (data->bonus == 1 && (keysym == XK_d || keysym == XK_Right))
		(set_dir(data, 3), new_move(data, pos, pos.x + 1, pos.y));
	return (0);
}
