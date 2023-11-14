/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:32:32 by ael-kace          #+#    #+#             */
/*   Updated: 2023/10/23 13:18:42 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	distance_between_points(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

void	hor_intercept(t_player *player, int i, double *xintercept,
	double *yintercept)
{
	double	xstep;
	double	ystep;

	hor_step_calculator(player, i, &xstep, &ystep);
	if (player->ray[i].up_ray)
		*yintercept -= 1;
	while (!has_wall(player, *xintercept, *yintercept))
	{
		*xintercept += xstep;
		*yintercept += ystep;
	}
}

void	ver_intercept(t_player *player, int i, double *xintercept,
	double *yintercept)
{
	double	xstep;
	double	ystep;

	ver_step_calculator(player, i, &xstep, &ystep);
	if (player->ray[i].left_ray)
		*xintercept -= 1;
	while (!has_wall(player, *xintercept, *yintercept))
	{
		*xintercept += xstep;
		*yintercept += ystep;
	}
}

double	*cast_horizontal(t_player *player, int i)
{
	double	xintercept;
	double	yintercept;
	double	*r;

	r = malloc(sizeof(double) * 2);
	if (!r)
		return (NULL);
	yintercept = floor(player->y / player->mes.tile_size)
		* player->mes.tile_size;
	if (player->ray[i].down_ray)
		yintercept += player->mes.tile_size;
	xintercept = player->x + ((yintercept - player->y)
			/ tan(player->ray[i].ray_angle));
	hor_intercept(player, i, &xintercept, &yintercept);
	r[0] = xintercept;
	r[1] = yintercept;
	return (r);
}

double	*cast_vertical(t_player *player, int i)
{
	double	xintercept;
	double	yintercept;
	double	*r;

	r = malloc(sizeof(double) * 2);
	if (!r)
		return (NULL);
	xintercept = floor(player->x / player->mes.tile_size)
		* player->mes.tile_size;
	if (player->ray[i].right_ray)
		xintercept += player->mes.tile_size;
	yintercept = player->y + ((xintercept - player->x)
			* tan(player->ray[i].ray_angle));
	ver_intercept(player, i, &xintercept, &yintercept);
	r[0] = xintercept;
	r[1] = yintercept;
	return (r);
}
