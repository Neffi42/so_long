/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:28:54 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/13 08:43:14 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!(data->mlx))
		end_game(error(-1, ERROR_MALLOC, NULL), data);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, \
	"The Binding of so_long");
	if (!(data->win))
		end_game(error(-1, ERROR_MALLOC, NULL), data);
	data->imgs = calloc(NBR_IMGS, sizeof(t_img));
	if (!(data->imgs))
		end_game(error(-1, ERROR_MALLOC, NULL), data);
}
