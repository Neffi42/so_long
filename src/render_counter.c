/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_counter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:55:16 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/16 12:32:14 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	find_image(int nbr)
{

}

void	render_counter(t_data *data)
{
	t_map	*map;
	size_t	i;
	size_t	div;

	map = &(data->maps[data->i]);
	i = -1; 
	div = 10 * (ft_nbrlen(map->player.moves) - 1);
	put_image(data, MOVE, 0, 0);
	put_image(data, SEMI_COL, 1, 0);
	while (++i < len)
		put_image(data, \
		find_image(map->player.moves / (10 * (len - 1 - i))), 2 + i, 0);
}
