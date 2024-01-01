/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:05:31 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/14 09:36:56 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vec	translation(int x, int y, int dest_x, int dest_y)
{
	t_vec	vec;

	vec.x = dest_x - x;
	vec.y = dest_y - y;
	return (vec);
}
