/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:28:54 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/10 19:36:22 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_mlx(t_mlx *mlx, t_map *maps)
{
	mlx->mlx = mlx_init();
	if (!(mlx->mlx))
		end_game(error(ERROR_MALLOC, NULL), maps, NULL);
	mlx->win = mlx_new_window(mlx->mlx, 1920, 1080, "The Binding of so_long");
	if (!(mlx->win))
		end_game(error(ERROR_MALLOC, NULL), maps, mlx);
	return (1);
}
