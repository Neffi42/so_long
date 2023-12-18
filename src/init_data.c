/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:54:18 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/18 10:59:48 by abasdere         ###   ########.fr       */
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
}
