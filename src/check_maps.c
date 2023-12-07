/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:34:49 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/07 16:12:42 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*check_map(const char *map_file)
{
	int		fd;
	char	*map;
	char	*tmp;
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

static int	check_suffix(const char *map_file)
{
	size_t	len;

	len = ft_strlen(map_file);
	if (len < 4 || map_file[len - 4] != '.' || map_file[len - 3] != 'b'\
		|| map_file[len - 2] != 'e' || map_file[len - 1] != 'r')
		return (0);
	return (1);
}

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
		if (!check_suffix(av[i + 1]) && !free_split(maps))
			error(ERROR_INVALID_MAP);
		maps[i] = check_map(av[i + 1]);
		if (!maps[i] && !free_split(maps))
			error(ERROR_INVALID_MAP);
		ft_dprintf(1, "%s", maps[i]);
	}
	return (maps);
}
