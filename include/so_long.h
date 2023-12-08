/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:31:15 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/08 12:36:42 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/include/libft.h"
# include "../lib/minilibx/mlx.h"

# define ERROR_NBR_ARG "To start the game, please provide a valid map"
# define ERROR_INVALID_MAP "is invalid, please try again with another one"
# define ERROR_INVALID_SUFFIX "is invalid, please provide a .ber file"
# define ERROR_INVALID_SHAPE "is invalid, the map must be a rectangle"
# define ERROR_NBR_PLAYER "is invalid, the map must contain \
	one starting position"
# define ERROR_NBR_EXIT "is invalid, the map must contain one exit"
# define ERROR_NBR_COINS "is invalid, the map must contain \
	at least one collectible"
# define ERROR_MALLOC "Malloc failed!"

typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;

typedef struct s_map
{
	size_t	nbr_coins;
	t_pos	*coins;
	int		nbr_exit;
	t_pos	exit;
	int		nbr_player;
	t_pos	player;
	size_t	height;
	size_t	width;
	int		is_rectangle;
	char	**map;
}	t_map;

typedef struct s_maps{
	t_map	*maps;
}	t_maps;

int		error(char *message, const char *file);
void	end_game(int status, t_map *maps);
void	free_maps(t_map *maps);
t_map	*check_maps(size_t ac, const char **av);
void	init_pos(t_pos *pos, float x, float y);
void	init_map(t_map *map);

#endif
