/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:12:35 by gmorais-          #+#    #+#             */
/*   Updated: 2024/02/15 17:02:39 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cub3d.h"

float	angle_from_map(char o)
{
	if (o == 'N')
		return (3 * M_PI / 2);
	else if (o == 'W')
		return (M_PI);
	else if (o == 'E')
		return (0);
	else
		return (M_PI_2);
}

t_player	*init_player(t_player *player, t_map *map)
{
	player = malloc(sizeof(t_player));
	player->x = map->p_y * TILES + TILES / 2;
	player->y = map->p_x * TILES + TILES / 2;
	player->ang = angle_from_map(map->orientation);
	player->dx = cos(player->ang) * 5;
	player->dy = sin(player->ang) * 5;
	return (player);
}
