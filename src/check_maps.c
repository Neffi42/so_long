/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:34:49 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/08 15:49:54 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*check_maps(size_t ac, const char **av)
{
	size_t	i;
	t_map	*maps;

	i = -1;
	maps = ft_calloc(ac, sizeof(t_map));
	if (!maps)
		error(ERROR_MALLOC, NULL);
	init_map(maps + (ac - 1));
	while (++i + 1 < ac)
		check_map(maps, i, av[i + 1]);
	return (maps);
}
