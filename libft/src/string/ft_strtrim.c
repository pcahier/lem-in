/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:51:02 by agrossma          #+#    #+#             */
/*   Updated: 2017/11/13 18:03:00 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Count the number of ' ', '\n' or '\t' at the beginning of the string
** \param s The string to count into
** \return The number of spaces
*/

static size_t	ft_count_space_beginning(char const *s)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		count++;
		i++;
	}
	return (count);
}

/*
** Count the numner of ' ', '\n' or '\t' at the end of the string
** \param s The string to count into
** \return The number of spaces
*/

static size_t	ft_count_space_end(char const *s)
{
	size_t	count;
	int		i;

	i = ft_strlen(s) - 1;
	count = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		count++;
		i--;
	}
	return (count);
}

/*
** Allocate (with malloc) and returns a copy of the passed string without the
** whitespaces at the beginning and the end. Whitespaces are the characters
** ' ', '\n' and '\t'. If s doesn't contain any whitespaces, it returns a copy
** of s.
** \param s The string to trim
** \return The trimmed string or NULL if the allocation failed
*/

char			*ft_strtrim(char const *s)
{
	char	*trim;
	size_t	space_beginning;
	size_t	space_end;
	size_t	len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	space_beginning = ft_count_space_beginning(s);
	space_end = ft_count_space_end(s);
	len = ft_strlen(s);
	if (len - space_beginning <= 0)
		return (ft_strdup(""));
	MALLOC_CHECK((trim = ft_strnew(len - space_beginning - space_end)));
	i = 0;
	while (i + space_beginning < len - space_end)
	{
		trim[i] = s[i + space_beginning];
		i++;
	}
	return (trim);
}
