/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:31:15 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/07 16:23:18 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

# define ERROR_NBR_ARG "To start the game, please provide a valid map"
# define ERROR_INVALID_MAP "Map invalid, please try again with another one"
# define ERROR_MALLOC "Malloc failed!"

typedef struct s_player
{
	float	x;
	float	y;
	float	hp;
}	t_player;

void	error(char *s);
void	end_game(int status, char **maps);
char	**check_maps(size_t ac, const char **av);

#endif
