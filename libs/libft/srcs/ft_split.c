/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:05:35 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/14 10:44:49 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	const	*find_next_sep(char const *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (s);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		cw;
	char const	*next;
	char		**split_s;

	if (!s || !*s)
		return (NULL);
	i = -1;
	cw = ft_count_words(s, c);
	split_s = ft_calloc(cw + 1, sizeof(char *));
	if (!split_s)
		return (NULL);
	while (++i < cw)
	{
		while (*s == c)
			s++;
		next = find_next_sep(s, c);
		split_s[i] = ft_substr(s, 0, (next - s));
		if (!split_s[i])
			return (ft_free_tab(split_s));
		s = next + 1;
	}
	split_s[i] = NULL;
	return (split_s);
}
