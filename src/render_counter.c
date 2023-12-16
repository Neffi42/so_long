/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_counter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:55:16 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/16 16:33:52 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_counter(t_data *data)
{
	t_map	*map;
	size_t	i;
	char	*nbr;

	map = &(data->maps[data->i]);
	i = -1;
	nbr = ft_itoa(map->player.moves);
	if (!nbr)
		end_game(error(-1, ERROR_MALLOC, NULL), data);
	while (nbr[++i])
		put_image(data, DIGIT_0 + nbr[i] - '0', 1 + i, -1);
	free(nbr);
}

void	render_counter(t_data *data)
{
	put_image(data, MOVE, -1, -1);
	put_image(data, SEMI_COL, 0, -1);
	update_counter(data);
}
