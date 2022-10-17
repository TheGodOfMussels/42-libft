/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:05:12 by dimolin2          #+#    #+#             */
/*   Updated: 2022/10/10 15:05:13 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}