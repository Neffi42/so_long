/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:30:55 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/14 11:13:44 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->maps = NULL;
	data->imgs = NULL;
	data->i = 0;
}

static int	handle_no_event(void *mlx)
{
	(void)mlx;
	return (0);
}

static void	fill_window(t_data *data)
{
	size_t	i;
	size_t	j;
	t_vec	vec;

	i = -1;
	data->imgs[data->i].img = mlx_xpm_file_to_image(data->mlx, \
	"./textures/stems/floor.xpm", &data->imgs[data->i].width, &data->imgs[data->i].height);
	if (!data->imgs[data->i].img)
		end_game(error(-1, ERROR_MALLOC, NULL), data);
	vec = translation((data->maps[data->i].width + 1) / 2 * TILE_LEN, \
	(data->maps[data->i].height + 2) / 2 * TILE_LEN, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	while (++i < data->maps[data->i].height)
	{
		j = -1;
		while (++j < data->maps[data->i].width)
		{
				mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[0].img, j * TILE_LEN + vec.x, i * TILE_LEN + vec.y);
		}
	}
}

int	main(int ac, const char **av)
{
	t_data	data;

	if (ac < 2)
		end_game(error(-2, ERROR_NBR_ARG, NULL), NULL);
	init_data(&data);
	check_maps(ac, av, &data);
	init_mlx(&data);
	fill_window(&data);
	mlx_loop_hook(data.mlx, &handle_no_event, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &event_keypress, &data);
	mlx_hook(data.win, DestroyNotify, 0, &event_destroy, &data);
	mlx_loop(data.mlx);
	end_game(0, &data);
}
