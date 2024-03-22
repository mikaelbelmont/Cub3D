/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_inter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:12:24 by gmorais-          #+#    #+#             */
/*   Updated: 2024/02/05 21:12:25 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cub3d.h"
#include <limits.h>

void	set_initial_ray_values(t_ray *ray, float ang, t_mlx *m)
{
	ray->xwall = 0;
	ray->ywall = 0;
	ray->r_ang = normalize_ang(ang);
	ray->r_dir = upordown(ray->r_ang);
	ray->r_lor = leftorright(ray->r_ang);
	ray->yinter = floor(m->p->y / TILES) * TILES;
	if (ray->r_dir == DOWN)
		ray->yinter += TILES;
	ray->xinter = m->p->x + (ray->yinter - m->p->y) / tan(ray->r_ang);
	ray->ystep = TILES;
	if (ray->r_dir == UP)
		ray->ystep *= -1;
	ray->xstep = TILES / tan(ray->r_ang);
	if ((ray->r_lor == LEFT && ray->xstep > 0)
		|| (ray->r_lor == RIGHT && ray->xstep < 0))
		ray->xstep *= -1;
	ray->nextx = ray->xinter;
	ray->nexty = ray->yinter;
}

int	ft_ternarie(float dir, int macro)
{
	if (dir == macro)
		return (1);
	return (0);
}

void	loop_until_find_wall(t_mlx *m, t_ray *ray)
{
	while (ray->nextx >= 0 && ray->nexty >= 0)
	{
		if (has_wall(ray->nextx, ray->nexty - ft_ternarie(ray->r_dir, UP), m))
		{
			ray->xwall = ray->nextx;
			ray->ywall = ray->nexty;
			ray->hit = 1;
			break ;
		}
		else
		{
			ray->nextx += ray->xstep;
			ray->nexty += ray->ystep;
		}
	}
}

t_point	horizontalinter(t_mlx *m, float ang)
{
	t_point	inter;
	t_ray	ray;

	inter.dist2pl = INT_MAX;
	ray.hit = 0;
	set_initial_ray_values(&ray, ang, m);
	loop_until_find_wall(m, &ray);
	inter.x = ray.xwall;
	inter.y = ray.ywall;
	inter.hit = 1;
	if (ray.hit)
		inter.dist2pl = distancebetween(m->p->x, m->p->y, ray.xwall, ray.ywall);
	return (inter);
}
