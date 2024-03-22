/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <mbarreto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:15:05 by mbarreto          #+#    #+#             */
/*   Updated: 2024/02/05 21:15:06 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cub3d.h"

char	*ft_strcpy(char *dest, char *src)
{
	char	*p;
	int		i;

	p = dest;
	i = -1;
	while (src[++i] != '\0')
		p[i] = src[i];
	return (dest);
}

void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = str;
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	ptr = malloc(size * n);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * n);
	return (ptr);
}

void	*ft_memset(void *str, int c, size_t count)
{
	char	*dest;

	dest = (char *)str;
	while (0 < count)
	{
		dest[count - 1] = c;
		count--;
	}
	return (str);
}
