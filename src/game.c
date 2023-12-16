/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:03:15 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/16 16:00:22 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	handle_no_event(void *mlx)
{
	(void)mlx;
	return (0);
}

void	start_game(t_data *data)
{
	init_mlx(data);
	init_imgs(data);
	render_level(data);
	// render_counter(data);
	render_character(data);
	mlx_loop_hook(data->mlx, &handle_no_event, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &event_keypress, data);
	mlx_hook(data->win, DestroyNotify, 0, &event_destroy, data);
	mlx_loop(data->mlx);
}

void	next_map(t_data *data)
{
	mlx_loop_end(data->mlx);
	if (++(data->i) < data->len)
	{
		destroy_mlx(data);
		start_game(data);
	}
	end_game(0, data);
}
