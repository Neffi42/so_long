/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:07:26 by abasdere          #+#    #+#             */
/*   Updated: 2024/01/01 16:17:22 by abasdere         ###   ########.fr       */
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

static void	parse_lines(t_data *data, int fd, const char *map_file, t_map *map)
{
	char	*l1;
	char	*l2;
	size_t	len;

	l1 = ft_get_next_line(fd);
	map->width = ft_strlen(l1) - 1;
	l2 = ft_get_next_line(fd);
	while (l2 && ++(map->height))
	{
		len = ft_strlen(l2);
		if (l2[len -1] == '\n')
			len--;
		if (len != map->width && free_parse(l1, l2, fd))
			end_game(error(-5, ERROR_INVALID_SHAPE, map_file), data);
		l1 = ft_freejoin(l1, l2, 2);
		l2 = ft_get_next_line(fd);
	}
	map->map = ft_split(l1, '\n');
	free_parse(l1, l2, fd);
	if (!map->map)
		end_game(error(-1, ERROR_MALLOC, map_file), data);
	find_all_chars(data, map);
	map->is_rectangle = 1;
}

static void	parse_map(t_data *data, t_map *map, const char *map_file, int fd)
{
	init_map(map, map_file);
	parse_lines(data, fd, map_file, map);
	if (data->bonus)
	{
		map->foes = ft_calloc(map->nbr_foes + 1, sizeof(t_pos));
		if (!map->foes)
			end_game(error(-1, ERROR_MALLOC, NULL), data);
	}
}

static int	check_walls(t_map map)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < map.height)
	{
		j = -1;
		if (!i || i == map.height - 1)
		{
			while (j < map.width && map.map[i][j])
				if (map.map[i][++j] != '1')
					return (0);
		}
		else if (map.map[i][0] != '1' || map.map[i][map.width - 1] != '1')
			return (0);
	}
	return (1);
}

void	check_map(t_data *data, size_t i, const char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0 || !check_suffix(map_file))
		end_game(error(-3, ERROR_INVALID_SUFFIX, map_file), data);
	parse_map(data, &(data->maps[i]), map_file, fd);
	if (!(data->maps[i].is_rectangle))
		end_game(error(-5, ERROR_INVALID_SHAPE, map_file), data);
	if ((data->maps[i].width + 2) * TILE_LEN > MAX_WIDTH || \
	(data->maps[i].height + 2) * TILE_LEN >= MAX_HEIGHT)
		end_game(error(-11, ERROR_MAP_TOO_BIG, map_file), data);
	if (!(data->maps[i].nbr_player) || (data->maps[i].nbr_player) > 1)
		end_game(error(-6, ERROR_NBR_PLAYER, map_file), data);
	if (!(data->maps[i].nbr_exit) || (data->maps[i].nbr_exit) > 1)
		end_game(error(-7, ERROR_NBR_EXIT, map_file), data);
	if (!(data->maps[i].nbr_coins))
		end_game(error(-8, ERROR_NBR_COINS, map_file), data);
	if (!data->maps[i].map)
		end_game(error(-1, ERROR_MALLOC, map_file), data);
	if (!check_walls(data->maps[i]))
		end_game(error(-9, ERROR_INVALID_WALLS, map_file), data);
	if (!flood_map(&(data->maps[i]), data->bonus))
		end_game(error(-10, ERROR_INVALID_PATH, map_file), data);
}
