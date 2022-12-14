/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:57:00 by dimolin2          #+#    #+#             */
/*   Updated: 2022/10/17 19:57:01 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	count;
	size_t	flag;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (count);
}

static size_t	move_ptr(char const *s, size_t n, size_t *index, char c)
{
	size_t	i;

	i = 0;
	if (c < 0)
	{
		*index = *index + 1;
		while (n)
		{
			if (*s == '\0')
				return (i);
			s++;
			n--;
			i++;
		}
	}
	else
	{
		while (s[i] == c)
			i++;
	}
	return (i);
}

static char	*word_dup(const char *str, int size)
{
	char	*word;

	word = (char *) malloc ((size + 1) * sizeof (char));
	if (!word)
		return (NULL);
	ft_strlcpy (word, str, size + 1);
	return (word);
}

static char	**free_all(char **ptr, size_t count)
{
	while (count)
	{
		free(ptr[count]);
		count--;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	const char	*str;
	char		**ptr;
	size_t		i;

	if (!s)
		return (NULL);
	str = s;
	ptr = (char **) malloc ((word_count(s, c) + 1) * sizeof (char *));
	i = 0;
	while (*s != '\0' && ptr)
	{
		s += move_ptr(s, 0, 0, c);
		if (*s == '\0')
			break ;
		str = ft_strchr(s, c);
		if (!str)
			str = (char *) s + ft_strlen(s);
		ptr[i] = (char *) word_dup(s, str - s);
		if (!ptr[i])
			return (free_all(ptr, i + 1));
		s += move_ptr(s, str - s, &i, -1);
	}
	if (ptr)
		ptr[i] = 0;
	return (ptr);
}
