/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:15:46 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/18 15:47:23 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos	pathfinder(t_data *data, t_pos src, t_pos dest)
{
	t_pos	pos;
	t_dmap	**dmap;

	dmap = init_dmap(data, src, dest);
	return ((void)free_dmap(dmap), pos);
}
