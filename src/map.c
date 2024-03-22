/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:12:47 by gmorais-          #+#    #+#             */
/*   Updated: 2024/02/05 21:17:42 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cub3d.h"

int	check_empty(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '0')
		return (1);
	return (0);
}

int	draw_map(t_mlx *mlx)
{
	int			square_size;
	t_point		point;
	int			col;
	int			row;

	square_size = sqrt((WIDTH * HEIGHT) / 4) / mlx->m->width;
	row = -1;
	while (mlx->m->minimap[++row])
	{
		col = -1;
		while (mlx->m->minimap[row][++col])
		{
			point.x = col * square_size;
			point.y = row * square_size;
			if (mlx->m->minimap[row][col] == '1')
				mlx_square(mlx, point, square_size, 0x000000);
			else if (check_empty(mlx->m->minimap[row][col]))
				mlx_square(mlx, point, square_size, 0xFFFFFF);
			else
				continue ;
		}
	}
	return (square_size);
}

void	displaymap(t_mlx *mlx)
{
	t_point	map_player;
	t_point	map_dir;
	int		sq;
	float	scale;

	sq = draw_map(mlx);
	scale = (float)sq / (float)TILES;
	map_player.x = mlx->p->x * scale - sq / 4;
	map_player.y = mlx->p->y * scale - sq / 4;
	map_dir.x = map_player.x + mlx->p->dx * 5;
	map_dir.y = map_player.y + mlx->p->dy * 5;
	mlx_square(mlx, map_player, sq / 2, 0xFF0000);
	mlx_line_to(mlx, map_player, map_dir, 0xFF0000);
	mlx_put_image_to_window(mlx->ptr, mlx->mlx_win, mlx->img, 0, 0);
}
