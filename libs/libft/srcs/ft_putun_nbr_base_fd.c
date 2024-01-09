/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun_nbr_base_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:24:25 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/27 16:30:47 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_recu(unsigned long n, char *base, size_t b_size, int fd)
{
	int	len;

	len = 1;
	if (n / b_size)
		len += ft_nb_recu(n / b_size, base, b_size, len);
	n = base[n % b_size];
	write(fd, &n, 1);
	return (len);
}

int	ft_putun_nbr_base_fd(unsigned long n, char *base, int fd)
{
	size_t	b_size;
	int		len;

	len = 0;
	b_size = ft_strlen(base);
	if (ft_check_base(base, b_size))
		len += ft_nb_recu(n, base, b_size, fd);
	return (len);
}
