/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:04:16 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/29 19:26:08 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert_flag(char c, va_list *ap, int fd)
{
	if (c == 'c')
		return (ft_count_putchar_fd(va_arg(*ap, int), fd));
	else if (c == 's')
		return (ft_s_flag(va_arg(*ap, char *), fd));
	else if (c == 'p')
		return (ft_p_flag(va_arg(*ap, unsigned long), fd));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_base_fd(va_arg(*ap, int), DECI_BASE, fd));
	else if (c == 'u')
		return (ft_putnbr_base_fd(va_arg(*ap, unsigned int), DECI_BASE, fd));
	else if (c == 'x')
		return (ft_putnbr_base_fd(va_arg(*ap, unsigned int), X_BASE_LO, fd));
	else if (c == 'X')
		return (ft_putnbr_base_fd(va_arg(*ap, unsigned int), X_BASE_UP, fd));
	else if (c == '%')
		return (ft_count_putchar_fd('%', fd));
	return (FALSE);
}

static int	read_flag(const char *s, va_list *ap, int *i, int *len)
{
	int		l;

	l = 0;
	if (ft_strchr(CONV_FLAGS, s[i[0] + 1]))
	{
		l = convert_flag(s[i[0] + 1], ap, i[1]);
		if (!l)
		{
			*len += 1;
			return (FALSE);
		}
		else if (l == -1)
			return (TRUE);
		*len += l;
	}
	return (TRUE);
}

int	ft_dprintf(int fd, const char *s, ...)
{
	int		i[2];
	int		start;
	int		len;
	va_list	ap;

	i[0] = -1;
	i[1] = fd;
	start = 0;
	len = 0;
	va_start(ap, s);
	while (s[++(i[0])])
	{
		if (!s[i[0] + 1])
			write(fd, &(s[start]), i[0] + 1 - start);
		if (s[i[0]] == '%')
		{
			write(fd, &(s[start]), i[0] - start);
			i[0] += read_flag(s, &ap, i, &len);
			start = i[0] + 1;
		}
		else
			len++;
	}
	va_end(ap);
	return (len);
}
