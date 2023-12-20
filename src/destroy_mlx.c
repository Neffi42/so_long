/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:38:46 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/20 08:38:56 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
