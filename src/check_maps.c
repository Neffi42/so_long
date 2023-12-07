/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:34:49 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/07 15:15:43 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*check_map(const char *map_file)
{
	int		fd;
	char	*map;
	char 	*tmp;
	size_t	s_map;

	fd = open(map_file, O_RDONLY);
	map = get_next_line(fd);
	tmp = get_next_line(fd);
	s_map = ft_strlen(map);
	while (tmp)
	{
		if (s_map != ft_strlen(tmp) && 0 <= close(fd))
			return (free(map), free(tmp), NULL);
		map = ft_freejoin(map, tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	return (map);
}

// check .ber
char	**check_maps(size_t ac, const char **av)
{
	size_t	i;
	char	**maps;

	i = -1;
	maps = ft_calloc(ac, sizeof(char *));
	if (!maps)
		error(ERROR_MALLOC);
	while (++i + 1 < ac)
	{
		maps[i] = check_map(av[i + 1]);
		if (!maps[i] && !free_split(maps))
			error(ERROR_INVALID_MAP);
		ft_dprintf(1, "%s\n", maps[i]);
	}
	return (maps);
}
