/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:41:59 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/18 16:19:20 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	find_ori(t_pos src, t_pos dest)
{
	if (src.x <= dest.x && src.y <= dest.y)
		return (1);
	else if (src.x <= dest.x && src.y > dest.y)
		return (2);
	else if (src.x > dest.x && src.y <= dest.y)
		return (3);
	return (4);
}

static t_pos	init_limit(int ori, t_pos src, t_pos dest)
{
	t_pos	limit;

	if (ori == 1)
		init_pos(&limit, dest.x - src.x, dest.y - src.y);
	else if (ori == 2)
		init_pos(&limit, dest.x - src.x, src.y - dest.y);
	else if (ori == 3)
		init_pos(&limit, src.x - dest.x, dest.y - src.y);
	else
		init_pos(&limit, src.x - dest.x, src.y - dest.y);
	return (limit);
}

static t_dmap	init_el(char c, int cost)
{
	t_dmap	el;

	el.c = c;
	el.cost = cost;
	return (el);
}

static t_dmap	*init_line(t_data *data, int ori, t_pos src, t_pos limit)
{
	t_dmap	*line;
	size_t	i;

	line = ft_calloc(limit.x + 1, sizeof(t_dmap));
	if (!line)
		end_game(error(-1, ERROR_MALLOC, NULL), data);
	i = -1;
	while (ori < 3 && ++i < limit.x)
		line[i] = init_el(data->maps[data->i].map[src.y][src.x + i], -1);
	i = limit.x;
	while (ori > 2 && i-- > 0)
		line[i] = init_el(data->maps[data->i].map[src.y][src.x - i], -1);

}

t_dmap	**init_dmap(t_data *data, t_pos src, t_pos dest)
{
	size_t	i;
	int		ori;
	t_pos	limit;
	t_dmap	**dmap;

	ori = find_ori(src, dest);
	limit = init_limit(ori, src, dest);
	dmap = ft_calloc(limit.y + 1, sizeof(t_dmap));
	if (!dmap && !free_dmap(dmap))
		end_game(error(-1, ERROR_MALLOC, NULL), data);
	i = -1;
	limit.moves = - 1;
	if (!(ori % 2))
		limit.moves = - ;
	while (++i < limit.y)
	{
		if (ori % 2)
			init_pos(&src, src.x, );

		dmap[i] = init_line(data, ori, init_pos(&src, src.x, src.y + i), limit);
		if (!dmap[i] && !free_dmap(dmap))
			end_game(error(-1, ERROR_MALLOC, NULL), data);
	}
	return (dmap);
}
