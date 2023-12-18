/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:21:25 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/18 12:23:47 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_maps(t_data *data)
{
	size_t	i;

	i = -1;
	while (data->maps && data->maps[++i].map)
	{
		if (data->bonus)
			free(data->maps[i].pos_foes);
		ft_free_tab(data->maps[i].map);
	}
	free(data->maps);
}
