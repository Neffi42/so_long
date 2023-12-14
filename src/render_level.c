/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_level.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:30:28 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/14 16:26:44 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_floor(t_data *data)
{
	size_t	i;
	size_t	j;
	int		x;

	i = -1;
	while (++i < data->maps[data->i].height)
	{
		j = -1;
		while (++j < data->maps[data->i].width)
		{
			x = ft_rand() % 4;
			if (x < 0)
				x = -x;
			put_image(data, x, j, i);
		}
	}
}

static void	render_corners(t_data *data)
{
	put_image(data, 4, 0, 0);
	put_image(data, 5, 0, data->maps[data->i].height - 1);
	put_image(data, 6, data->maps[data->i].width - 1, 0);
	put_image(data, 7, data->maps[data->i].width - 1, \
	data->maps[data->i].height - 1);
}

static void	render_walls(t_data *data)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < data->maps[data->i].height)
	{
		j = -1;
		if (!i)
			while (++j < data->maps[data->i].width - 1)
				put_image(data, 8, j, i);
		else if (i + 1 == data->maps[data->i].height)
			while (++j < data->maps[data->i].width - 1)
				put_image(data, 10, j, i);
		else
		{
			put_image(data, 9, 0, i);
			put_image(data, 11, data->maps[data->i].width - 1, i);
		}
	}
}

void	render_level(t_data *data)
{
	render_floor(data);
	render_walls(data);
	render_corners(data);
}
