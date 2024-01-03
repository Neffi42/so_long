/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:57:34 by abasdere          #+#    #+#             */
/*   Updated: 2024/01/03 13:00:01 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_maps(size_t ac, const char **av, t_data *data)
{
	size_t	i;

	i = -1;
	data->maps = ft_calloc(ac, sizeof(t_map));
	if (!data->maps)
		error(-1, ERROR_MALLOC, NULL);
	init_map(data->maps + (ac - 1), NULL);
	while (++i + 1 < ac)
		check_map(data, i, av[i + 1]);
}

void	next_map(t_data *data)
{
	mlx_loop_end(data->mlx);
	if (++(data->i) < data->len)
	{
		destroy_mlx(data);
		start_game(data);
	}
	end_game(message(WIN), data);
}

int	event_destroy(t_data *data)
{
	end_game(message(GAME_OVER), data);
	return (0);
}

int	message(char *message)
{
	ft_printf("%s\n", message);
	return (0);
}

int	error(int status, char *message, const char *file)
{
	if (file)
		ft_dprintf(2, "Error\n%s %s\n", file, message);
	else
		ft_dprintf(2, "Error\n%s\n", message);
	return (status);
}
