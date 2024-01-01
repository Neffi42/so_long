/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:45:38 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/20 08:49:15 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	next_map(t_data *data)
{
	mlx_loop_end(data->mlx);
	if (++(data->i) < data->len)
	{
		destroy_mlx(data);
		start_game(data);
	}
	end_game(message(WIN), data);
}
