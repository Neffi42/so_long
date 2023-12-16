/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:07:26 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/16 09:31:17 by abasdere         ###   ########.fr       */
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

static t_map	parse_map(t_data *data, int fd, const char *map_file)
{
	t_map	map;
	char	*l1;
	char	*l2;
	size_t	len;

	init_map(&map, map_file);
	l1 = ft_get_next_line(fd);
	l2 = ft_get_next_line(fd);
	map.width = ft_strlen(l1) - 1;
	find_all_chars(data, &map, l1, map.width);
	while (l2)
	{
		map.height++;
		len = ft_strlen(l2) - 1;
		if (map.width != len)
			return (free(l1), free(l2), (void)close(fd), map);
		find_all_chars(data, &map, l2, len);
		l1 = ft_freejoin(l1, l2);
		l2 = ft_get_next_line(fd);
	}
	if (!l2 && ++(map.is_rectangle))
		map.map = ft_split(l1, '\n');
	return (free(l1), free(l2), (void)close(fd), map);
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
			while (++j < map.width)
				if (map.map[i][j] != '1')
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
	data->maps[i] = parse_map(data, fd, map_file);
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
	if (!flood_map(&(data->maps[i])))
		end_game(error(-10, ERROR_INVALID_PATH, map_file), data);
}
