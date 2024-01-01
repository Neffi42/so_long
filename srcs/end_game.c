/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:04:49 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/20 08:38:43 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(int status, t_data *data)
{
	if (!data)
		exit(status);
	if (data->maps)
		free_maps(data);
	destroy_mlx(data);
	exit(status);
}
