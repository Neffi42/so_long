/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:30:55 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/18 10:25:09 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, const char **av)
{
	t_data	data;

	if (ac < 2)
		end_game(error(-2, ERROR_NBR_ARG, NULL), NULL);
	init_data(&data, ac - 1, 0);
	check_maps(ac, av, &data);
	start_game(&data);
	end_game(message(GAME_OVER), &data);
}
