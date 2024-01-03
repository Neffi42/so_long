/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:40:53 by abasdere          #+#    #+#             */
/*   Updated: 2024/01/03 12:53:34 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	handle_no_event(t_data *data)
{
	(void)data;
	return (0);
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
	data->bonus = 1;
	mlx_hook(data->win, KeyPress, KeyPressMask, &event_keypress, data);
	mlx_loop_hook(data->mlx, &handle_no_event, data);
	mlx_hook(data->win, DestroyNotify, 0, &event_destroy, data);
	mlx_loop(data->mlx);
}

int	main(int ac, const char **av)
{
	t_data	data;

	if (ac < 2)
		end_game(error(-2, ERROR_NBR_ARG, NULL), NULL);
	init_data(&data, ac - 1, -1);
	check_maps(ac, av, &data);
	start_game(&data);
	end_game(message(GAME_OVER), &data);
}
