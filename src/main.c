/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:30:55 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/11 21:56:58 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->maps = NULL;
}

static int	handle_no_event(void *mlx)
{
	(void)mlx;
	return (0);
}

int	main(int ac, const char **av)
{
	t_data	data;

	if (ac < 2)
		end_game(error(ERROR_NBR_ARG, NULL), NULL);
	init_data(&data);
	check_maps(ac, av, &data);
	init_mlx(&data);
	mlx_loop_hook(data.mlx, &handle_no_event, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &event_keypress, &data);
	mlx_hook(data.win, DestroyNotify, 0, &event_destroy, &data);
	mlx_loop(data.mlx);
	end_game(0, &data);
}
