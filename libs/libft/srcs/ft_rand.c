/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:19:56 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/14 14:36:45 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_rand(void)
{
	int		fd;
	char	buf[1];

	fd = open("/dev/random", O_RDONLY);
	if (fd < 0 || read(fd, buf, 1) < 0)
		return ((void)close(fd), -1);
	close(fd);
	return (buf[0]);
}
