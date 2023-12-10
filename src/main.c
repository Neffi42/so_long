/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:30:55 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/10 19:33:07 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, const char **av)
{
	t_map	*maps;
	t_mlx	mlx;

	if (ac < 2)
		end_game(error(ERROR_NBR_ARG, NULL), NULL, NULL);
	maps = check_maps(ac, av);
	init_mlx(&mlx, maps);
	end_game(0, maps, &mlx);
}
