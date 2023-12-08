/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:34:49 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/08 12:32:22 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_suffix(const char *map_file)
{
	size_t	len;

	len = ft_strlen(map_file);
	if (len < 4 || map_file[len - 4] != '.' || map_file[len - 3] != 'b'\
		|| map_file[len - 2] != 'e' || map_file[len - 1] != 'r')
		return (0);
	return (1);
}

static void	find_element(t_map *map, char *line, char el)
{
	char	*i;

	i = ft_strchr(line, el);
	if (i && el == 'P' && ++(map->nbr_player))
		init_pos(&(map->player), i - line, map->height - 1);
	else if (i && el == 'E' && ++(map->nbr_player))
		init_pos(&(map->player), i - line, map->height - 1);
	else if (i && el == 'C')
		++(map->nbr_coins);
}

static t_map	parse_map(int fd)
{
	t_map	map;
	char	*line1;
	char	*line2;

	init_map(&map);
	line1 = get_next_line(fd);
	line2 = get_next_line(fd);
	map.width = ft_strlen(line1);
	while (line2)
	{
		map.height++;
		if (map.width != ft_strlen(line2))
			break ;
		find_element(&map, line2, 'P');
		find_element(&map, line2, 'E');
		find_element(&map, line2, 'C');
		line1 = ft_freejoin(line1, line2);
		line2 = get_next_line(fd);
	}
	if (!line2 && ++(map.is_rectangle))
		map.map = ft_split(line1, '\n');
	return (free(line1), free(line2), (void)close(fd), map);
}

static void	check_map(t_map **maps, size_t i, const char *map_file)
{
	if (!check_suffix(map_file))
		end_game(error(ERROR_INVALID_SUFFIX, map_file), *maps);
	(*maps)[i] = parse_map(open(map_file, O_RDONLY));
	if (!((*maps)[i].is_rectangle))
		end_game(error(ERROR_INVALID_SHAPE, map_file), *maps);
	if (!((*maps)[i].nbr_player) || ((*maps)[i].nbr_player) > 1)
		end_game(error(ERROR_NBR_PLAYER, map_file), *maps);
	if (!((*maps)[i].nbr_exit) || ((*maps)[i].nbr_exit) > 1)
		end_game(error(ERROR_NBR_EXIT, map_file), *maps);
	if (!((*maps)[i].nbr_coins))
		end_game(error(ERROR_NBR_COINS, map_file), *maps);
}

t_map	*check_maps(size_t ac, const char **av)
{
	size_t	i;
	size_t	j;
	t_map	*maps;

	i = -1;
	maps = ft_calloc(ac, sizeof(t_map));
	if (!maps)
		error(ERROR_MALLOC, NULL);
	while (++i + 1 < ac)
	{
		check_map(&maps, i, av[i + 1]);
		j = -1;
		while (maps[i].map[++j])
			ft_dprintf(1, "%s\n", maps[i].map[j]);
	}
	return (maps);
}
