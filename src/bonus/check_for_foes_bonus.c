/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_foes_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:57:34 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/19 14:41:45 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_for_foes(t_data *data)
{
	size_t	i;
	t_pos	*pos;

	if (!data->maps[data->i].nbr_foes)
		return ;
	i = -1;
	pos = &(data->maps[data->i].player);
	while (++i < data->maps[data->i].nbr_foes)
	{
		if (pos->x == data->maps[data->i].foes[i].x && \
		pos->y == data->maps[data->i].foes[i].y)
		{
			data->bonus = 2;
			put_image(data, LOST_D, pos->x, pos->y);
			message(CONTINUE);
		}
	}
}
