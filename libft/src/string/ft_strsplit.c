/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:51:02 by agrossma          #+#    #+#             */
/*   Updated: 2018/01/25 14:54:16 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Count the number of words in the string
** \param s The string
** \param c The character to escape
** \return The number of words
*/

static size_t	ft_count_words(char *s, char c)
{
	size_t		count;
	int			in_substring;

	count = 0;
	in_substring = 0;
	while (*s)
	{
		if (in_substring == 1 && *s == c)
			in_substring = 0;
		if (in_substring == 0 && *s != c)
		{
			in_substring = 1;
			count++;
		}
		s++;
	}
	return (count);
}

/*
** Count the length of a word in the string
** \param s The string
** \param c The character to escape
** \return The length of the word
*/

static size_t	ft_word_len(char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

/*
** Allocate with malloc and return an array of fresh string (all terminated by a
** '\0', even the array) resulting in the splitting of s at the character c
** \param s The string to split
** \param c The character of the splitting
** \return The array of strings or NULL if an allocation fails
*/

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	nb_words;
	int		i;

	if (s == NULL)
		return (NULL);
	nb_words = ft_count_words((char *)s, c);
	MALLOC_CHECK(
			(split = (char **)ft_memalloc((nb_words + 1) * sizeof(char *))));
	i = 0;
	while (nb_words--)
	{
		while (*s == c)
			s++;
		split[i] = ft_strsub((char *)s, 0, ft_word_len((char *)s, c));
		MALLOC_CHECK(split[i++]);
		s += ft_word_len((char *)s, c);
	}
	return (split);
}
