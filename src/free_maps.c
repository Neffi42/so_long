/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:21:25 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/15 10:52:54 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_maps(t_map *maps)
{
	size_t	i;

	i = -1;
	if (!maps)
		return ;
	while (maps[++i].map != NULL)
		ft_free_tab(maps[i].map);
	free(maps);
}
