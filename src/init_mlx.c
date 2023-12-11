/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:28:54 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/11 15:20:26 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!(mlx->mlx))
		return (0);
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, \
	"The Binding of so_long");
	if (!(mlx->win))
		return ((void)mlx_destroy_display(mlx->mlx), free(mlx->mlx), 0);
	return (1);
}
