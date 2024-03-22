/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <mbarreto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:14:51 by mbarreto          #+#    #+#             */
/*   Updated: 2024/02/05 21:14:52 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cub3d.h"

int	set_line_ter(int start, int end)
{
	if (start < end)
		return (1);
	return (-1);
}

void	cast_rays(t_mlx *m)
{
	t_line	l;
	int		i;

	i = -1;
	l.r_angle = m->p->ang - (FOV / 2);
	while (++i < m->win_x)
	{
		set_raycasting_values(&l, m);
		draw3dline(l, m, i);
		render_floor(m, i, l.drawend, l.drawstart);
		l.r_angle += (FOV / m->win_x);
	}
}
