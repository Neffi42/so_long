/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:34:49 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/11 21:21:37 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_maps(size_t ac, const char **av, t_data *data)
{
	size_t	i;

	i = -1;
	data->maps = ft_calloc(ac, sizeof(t_map));
	if (!data->maps)
		error(ERROR_MALLOC, NULL);
	init_map(data->maps + (ac - 1));
	while (++i + 1 < ac)
		check_map(data, i, av[i + 1]);
}
