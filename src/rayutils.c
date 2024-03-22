/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <mbarreto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:14:49 by mbarreto          #+#    #+#             */
/*   Updated: 2024/02/05 21:14:50 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cub3d.h"

float	normalize_ang(float angle)
{
	if (angle >= (2 * M_PI))
		angle -= (2 * M_PI);
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

int	upordown(float ang)
{
	if (ang >= 0 && ang <= M_PI)
		return (DOWN);
	else
		return (UP);
}

int	leftorright(float ang)
{
	if (ang >= M_PI_2 && ang <= (3 * M_PI_2))
		return (LEFT);
	else
		return (RIGHT);
}

double	distancebetween(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
