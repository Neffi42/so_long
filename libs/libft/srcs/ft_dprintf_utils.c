/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:42:32 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/11 12:48:51 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_putchar_fd(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int	ft_count_putstr_fd(const char *s, int fd)
{
	ft_putstr_fd(s, fd);
	return ((int)ft_strlen(s));
}

int	ft_s_flag(char *s, int fd)
{
	if (!s)
		return (ft_count_putstr_fd("(null)", fd));
	if (!(*s))
		return (-1);
	return (ft_count_putstr_fd(s, fd));
}

int	ft_p_flag(unsigned long p, int fd)
{
	if (!p)
		return (ft_count_putstr_fd("(nil)", fd));
	ft_putstr_fd("0x", fd);
	return (2 + ft_putun_nbr_base_fd((long long)p, X_BASE_LO, fd));
}
