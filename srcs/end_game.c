/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:04:49 by abasdere          #+#    #+#             */
/*   Updated: 2024/01/03 16:02:50 by abasdere         ###   ########.fr       */
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

void	free_maps(t_data *data)
{
	size_t	i;

	i = -1;
	while (data->maps && data->maps[++i].map)
	{
		if (data->bonus)
			free(data->maps[i].foes);
		ft_free_tab(data->maps[i].map);
	}
	free(data->maps);
}

int	free_parse(char *l1, char *l2, int fd)
{
	free(l1);
	free(l2);
	close(fd);
	return (1);
}

void	destroy_mlx(t_data *data)
{
	size_t	i;
	size_t	limit;

	i = -1;
	limit = NBR_IMGS;
	if (data->bonus)
		limit += BONUS_IMGS;
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	while (data->imgs && ++i < limit)
		if (data->imgs[i].img)
			mlx_destroy_image(data->mlx, data->imgs[i].img);
	if (data->imgs)
		free(data->imgs);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}
