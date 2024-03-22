/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:10:57 by gmorais-          #+#    #+#             */
/*   Updated: 2024/02/16 18:20:54 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cub3d.h"

int	strlen_special(char *s, int i)
{
	while (s[i] && s[i] == ' ')
		i++;
	return (i);
}

int	strlen_special2(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	i--;
	while (s[i] == ' ')
		i--;
	return (i);
}

void	check_gun(t_mlx *mlx)
{
	mlx->guntexture.img_ptr = mlx_xpm_file_to_image(mlx->ptr, \
		"./assets/gun0.xpm", &mlx->guntexture.w, &mlx->guntexture.h);
	if (mlx->guntexture.img_ptr == NULL)
		wrong_map(mlx);
	mlx->guntexture.addr = mlx_get_data_addr(mlx->guntexture.img_ptr, \
			&mlx->guntexture.bpp, &mlx->guntexture.line_len, \
			&mlx->guntexture.endian);
}

int	check_color_value(char *color)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if (color[i] == ' ' && color[i + 1])
			i++;
		if ((color[i] >= '0' && color[i] <= '9') && color[i + 1] == ' ')
		{
			i++;
			while (color[i] == ' ')
				i++;
			if (color[i] >= '0' && color[i] <= '9')
				return (1);
		}
		i++;
	}
	return (0);
}
