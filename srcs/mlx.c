/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:28:54 by abasdere          #+#    #+#             */
/*   Updated: 2024/01/03 12:59:03 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_win(t_data *data)
{
	data->win = mlx_new_window(data->mlx, \
	(data->maps[data->i].width + 2) * TILE_LEN, \
	(data->maps[data->i].height + 2) * TILE_LEN, "The Binding of so_long");
	if (!(data->win))
		end_game(error(-1, ERROR_MALLOC, NULL), data);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!(data->mlx))
		end_game(error(-1, ERROR_MALLOC, NULL), data);
	init_win(data);
}

void	destroy_mlx(t_data *data)
{
	size_t	i;

	i = 0;
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->imgs && data->bonus)
		while (i < NBR_IMGS + BONUS_IMGS && data->imgs[i].img)
			mlx_destroy_image(data->mlx, data->imgs[i++].img);
	else if (data->imgs && !data->bonus)
		while (i < NBR_IMGS && data->imgs[i].img)
			mlx_destroy_image(data->mlx, data->imgs[i++].img);
	if (data->imgs)
		free(data->imgs);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}
