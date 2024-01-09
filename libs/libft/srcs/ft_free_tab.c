/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:43:57 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/14 10:44:49 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free_tab(char **split_s)
{
	size_t	i;

	i = 0;
	if (!split_s)
		return (NULL);
	while (split_s[i])
		free(split_s[i++]);
	free(split_s);
	return (NULL);
}
