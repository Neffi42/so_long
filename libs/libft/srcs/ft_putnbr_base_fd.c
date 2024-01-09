/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:56:31 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/29 19:26:39 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_base_recu(long n, char *base, size_t b_size, int fd)
{
	int	len;

	len = 1;
	if (n / b_size)
		len += ft_putnbr_base_recu(n / b_size, base, b_size, fd);
	n = base[n % b_size];
	write(fd, &n, 1);
	return (len);
}

int	ft_check_base(char *base, size_t b_size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (b_size <= 1)
		return (FALSE);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (FALSE);
		while (base[i + 1] != '\0' && base[j])
			if (base[i] == base[j++])
				return (FALSE);
		i++;
	}
	return (TRUE);
}

int	ft_putnbr_base_fd(long n, char *base, int fd)
{
	size_t	b_size;
	int		len;

	len = 0;
	b_size = ft_strlen(base);
	if (ft_check_base(base, b_size))
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
			len++;
		}
		len += ft_putnbr_base_recu(n, base, b_size, fd);
	}
	return (len);
}
