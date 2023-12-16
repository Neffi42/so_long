/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:04:49 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/16 19:40:37 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_mlx(t_data *data)
{
	size_t	i;

	i = -1;
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->imgs && data->bonus)
		while (++i < NBR_IMGS + BONUS_IMGS)
			mlx_destroy_image(data->mlx, data->imgs[i].img);
	else if (data->imgs && !data->bonus)
		while (++i < NBR_IMGS)
			mlx_destroy_image(data->mlx, data->imgs[i].img);
	if (data->imgs)
		free(data->imgs);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->bonus && data->nbr_e)
		free(data->pos_e);
}

void	end_game(int status, t_data *data)
{
	if (!data)
		exit(status);
	if (data->maps)
		free_maps(data->maps);
	destroy_mlx(data);
	exit(status);
}
