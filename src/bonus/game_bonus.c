/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:03:15 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/19 14:30:35 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	handle_no_event(t_data *data)
{
	(void)data;
	return (0);
}

static void	exit_level(t_data *data)
{
	data->bonus = 3;
	render_tile(data, data->maps[data->i].player.x, \
	data->maps[data->i].player.y);
	put_image(data, LOST_JUMP2_1, data->maps[data->i].exit.x, \
	data->maps[data->i].exit.y);
	message(CONTINUE);
}

void	start_game(t_data *data)
{
	init_mlx(data);
	init_imgs(data);
	render_level(data);
	render_counter(data);
	render_character(data);
	if (data->maps[data->i].nbr_foes)
		render_foes(data);
	mlx_loop_hook(data->mlx, &handle_no_event, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &event_keypress, data);
	mlx_hook(data->win, DestroyNotify, 0, &event_destroy, data);
	mlx_loop(data->mlx);
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

void	next_map(t_data *data)
{
	mlx_loop_end(data->mlx);
	if (++(data->i) < data->len)
	{
		destroy_mlx(data);
		start_game(data);
	}
	end_game(message(WIN), data);
}
