/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:54:18 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/16 19:39:12 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *data, size_t len, int bonus)
{
	data->mlx = NULL;
	data->win = NULL;
	data->maps = NULL;
	data->imgs = NULL;
	data->i = 0;
	data->len = len;
	data->bonus = bonus;
	data->nbr_e = 0;
	data->pos_e = NULL;
}
