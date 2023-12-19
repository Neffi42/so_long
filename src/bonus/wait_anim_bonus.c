/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_anim_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:59:01 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/19 14:26:58 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wait_anim(int mul)
{
	t_timespec	s;

	s.tv_sec = 0;
	s.tv_nsec = ANIM_TIME * mul;
	nanosleep(&s, NULL);
}
