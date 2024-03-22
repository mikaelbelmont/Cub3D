/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:12:27 by gmorais-          #+#    #+#             */
/*   Updated: 2024/02/05 21:12:28 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cub3d.h"

void	init_map_struct(t_mlx *g)
{
	g->m->fd = 0;
	g->m->sky = NULL;
	g->m->floor = NULL;
	g->m->width = 0;
	g->m->height = 0;
	g->m->players = 0;
	g->m->sky_color = 0;
	g->m->floor_color = 0;
	g->m->orientation = '\0';
	g->m->sky_colors = NULL;
	g->m->floor_colors = NULL;
	g->m->floor = NULL;
	g->m->map = NULL;
	g->m->cub = NULL;
	g->m->texture = NULL;
	g->m->minimap = NULL;
}

void	free_double_arrays(t_mlx *g)
{
	int	i;

	i = -1;
	if (g->m->cub)
	{
		while (g->m->cub[++i])
			free(g->m->cub[i]);
		free(g->m->cub);
	}
	i = -1;
	if (g->m->texture)
	{
		while (++i < 4)
			free(g->m->texture[i]);
		free(g->m->texture);
	}
	i = -1;
	if (g->m->map)
	{
		while (g->m->map[++i])
			free(g->m->map[i]);
		free(g->m->map);
	}
}

void	free_map(t_mlx *g)
{
	int	i;

	if (g->m->sky)
		free(g->m->sky);
	if (g->m->floor)
		free(g->m->floor);
	if (g->m->sky_colors)
		free(g->m->sky_colors);
	if (g->m->floor_colors)
		free(g->m->floor_colors);
	free_double_arrays(g);
	i = -1;
	if (g->m->minimap)
	{
		while (g->m->minimap[++i])
			free(g->m->minimap[i]);
		free(g->m->minimap);
	}
	free(g->m);
}

void	wrong_map(t_mlx *g)
{
	free_map(g);
	printf("Please select a valid map\nFile Type must be cub\n");
	printf("The filetype of the textures must be xpm\n");
	printf("It should have only 1 player position\n");
	printf("The map must be close from all sides\n");
	exit(1);
}
