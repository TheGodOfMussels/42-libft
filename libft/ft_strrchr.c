/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:12:05 by dimolin2          #+#    #+#             */
/*   Updated: 2022/10/05 18:12:06 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	while (*str != '\0')
		str++;
	if (*str == '\0')
	{
		str--;
		while (*str != '\0')
		{
			if (*str == c)
				return ((char *) str);
			str--;
		}
	}
	return (NULL);
}
