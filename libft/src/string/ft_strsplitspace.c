/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:41:12 by agrossma          #+#    #+#             */
/*   Updated: 2018/04/16 17:43:04 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char *s)
{
	size_t		count;
	int			in_substring;

	count = 0;
	in_substring = 0;
	while (*s)
	{
		if (in_substring == 1 && ft_isspace(*s))
			in_substring = 0;
		if (in_substring == 0 && !ft_isspace(*s))
		{
			in_substring = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t	ft_word_len(char *s)
{
	size_t	len;

	len = 0;
	while (!ft_isspace(s[len]) && s[len])
		len++;
	return (len);
}

char			**ft_strsplitspace(char const *s)
{
	char	**split;
	size_t	nb_words;
	int		i;

	if (s == NULL)
		return (NULL);
	nb_words = ft_count_words((char *)s);
	MALLOC_CHECK(
			(split = (char **)ft_memalloc((nb_words + 1) * sizeof(char *))));
	i = 0;
	while (nb_words--)
	{
		while (ft_isspace(*s))
			s++;
		split[i] = ft_strsub((char *)s, 0, ft_word_len((char *)s));
		MALLOC_CHECK(split[i++]);
		s += ft_word_len((char *)s);
	}
	return (split);
}
