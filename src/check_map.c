/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:07:26 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/08 18:08:23 by abasdere         ###   ########.fr       */
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
	else if (i && el == 'E' && ++(map->nbr_exit))
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
	//check fd
	find_element(&map, line1, 'P');
	find_element(&map, line1, 'E');
	find_element(&map, line1, 'C');
	line2 = get_next_line(fd);
	map.width = ft_strlen(line1) - 1;
	while (line2)
	{
		map.height++;
		if (map.width != ft_strlen(line2) - 1)
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

static int	check_walls(t_map map)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < map.height)
	{
		j = -1;
		if (!i || i + 1 == map.height)
		{
			while (++j < map.width)
				if (map.map[i][j] != '1')
					return (0);
		}
		else if (map.map[i][0] != '1' || map.map[i][map.width - 1] != '1')
			return (0);
	}
	return (1);
}

void	check_map(t_map *maps, size_t i, const char *map_file)
{
	if (!check_suffix(map_file))
		end_game(error(ERROR_INVALID_SUFFIX, map_file), maps);
	maps[i] = parse_map(open(map_file, O_RDONLY));
	if (!(maps[i].is_rectangle))
		end_game(error(ERROR_INVALID_SHAPE, map_file), maps);
	if (!(maps[i].nbr_player) || (maps[i].nbr_player) > 1)
		end_game(error(ERROR_NBR_PLAYER, map_file), maps);
	if (!(maps[i].nbr_exit) || (maps[i].nbr_exit) > 1)
		end_game(error(ERROR_NBR_EXIT, map_file), maps);
	if (!(maps[i].nbr_coins))
		end_game(error(ERROR_NBR_COINS, map_file), maps);
	if (!maps[i].map)
		end_game(error(ERROR_MALLOC, map_file), maps);
	if (!check_walls(maps[i]))
		end_game(error(ERROR_INVALID_WALLS, map_file), maps);
	// flood map to check for valid path
	maps[i].coins = ft_calloc(maps[i].nbr_coins, sizeof(t_pos));
	if (!(maps[i]).coins)
		end_game(error(ERROR_MALLOC, map_file), maps);
	if (!flood_map(maps + i))
		end_game(error(ERROR_MALLOC, map_file), maps);
}
