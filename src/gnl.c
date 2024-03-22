/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:12:06 by gmorais-          #+#    #+#             */
/*   Updated: 2024/02/16 17:35:52 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cub3d.h"

int	ft_checknl(char *buff)
{
	int	i;
	int	j;
	int	is_new_line;

	i = -1;
	is_new_line = 0;
	j = 0;
	while (buff[++i])
	{
		if (is_new_line)
			buff[j++] = buff[i];
		if (buff[i] == '\n')
			is_new_line = 1;
		buff[i] = 0;
	}
	return (is_new_line);
}

static int	ft_strlen_nl(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\n' && str[len])
		len++;
	return (len + (str[len] == '\n'));
}

char	*ft_get_line(char *buff, char *line)
{
	int		i;
	int		j;
	int		buff_size;
	char	*new_line;

	buff_size = ft_strlen_nl(buff);
	new_line = malloc((buff_size + ft_strlen_nl(line) + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	i = -1 * (line != NULL);
	while (line && line[++i])
		new_line[i] = line[i];
	j = 0;
	while (j < buff_size)
		new_line[i++] = buff[j++];
	new_line[i] = '\0';
	if (line)
		free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	int			byte_read;
	static char	buff[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (NULL);
	line = NULL;
	byte_read = 1;
	while (1)
	{
		if (!buff[0])
			byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read > 0)
			line = ft_get_line(buff, line);
		if (ft_checknl(buff) || byte_read < 1)
			break ;
	}
	return (line);
}
