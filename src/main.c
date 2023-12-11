/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:30:55 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/11 16:22:50 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void *mlx)
{
	(void)mlx;
	return (0);
}

int	handle_keyrelease(int keysym, void *mlx)
{
	(void)keysym;
	(void)mlx;
	return (0);
}

int	handle_keypress(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(mlx->mlx, mlx->win);
	return (0);
}

int	handle_click(int button, int x, int y)
{
	ft_dprintf(1, "%d %d %d\n", button, x, y);
	return (0);
}

int	main(int ac, const char **av)
{
	t_map	*maps;
	t_mlx	mlx;

	if (ac < 2)
		end_game(error(ERROR_NBR_ARG, NULL), NULL, NULL);
	maps = check_maps(ac, av);
	if (!init_mlx(&mlx))
		end_game(error(ERROR_MALLOC, NULL), maps, NULL);
	mlx_loop_hook(mlx.mlx, &handle_no_event, &mlx);
	mlx_hook(mlx.win, KeyPress, KeyPressMask, &handle_keypress, &mlx);
	mlx_hook(mlx.win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &mlx);
	mlx_mouse_hook(mlx.win, &handle_click, &mlx);
	mlx_loop(mlx.mlx);
	end_game(0, maps, &mlx);
}
