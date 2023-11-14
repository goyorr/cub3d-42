/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:32:19 by ael-kace          #+#    #+#             */
/*   Updated: 2023/10/23 22:17:13 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	hor_step_calculator(t_player *player, int i, double *xstep,
	double *ystep)
{
	*ystep = player->mes.tile_size;
	if (player->ray[i].up_ray)
		*ystep *= -1;
	*xstep = player->mes.tile_size / tan(player->ray[i].ray_angle);
	if (player->ray[i].left_ray && *xstep > 0)
		*xstep *= -1;
	if (player->ray[i].right_ray && *xstep < 0)
		*xstep *= -1;
}

void	ver_step_calculator(t_player *player, int i, double *xstep,
	double *ystep)
{
	*xstep = player->mes.tile_size;
	if (player->ray[i].left_ray)
		*xstep *= -1;
	*ystep = player->mes.tile_size * tan(player->ray[i].ray_angle);
	if (player->ray[i].up_ray && *ystep > 0)
		*ystep *= -1;
	if (player->ray[i].down_ray && *ystep < 0)
		*ystep *= -1;
}

void	cast(t_player *player, int i)
{
	double	*hor_wall_hit;
	double	*ver_wall_hit;
	double	hor_distance;
	double	ver_distance;

	hor_wall_hit = NULL;
	ver_wall_hit = NULL;
	hor_wall_hit = cast_horizontal(player, i);
	ver_wall_hit = cast_vertical(player, i);
	ver_distance = distance_between_points(player->x, player->y,
			ver_wall_hit[0], ver_wall_hit[1]);
	hor_distance = distance_between_points(player->x, player->y,
			hor_wall_hit[0], hor_wall_hit[1]);
	player->ray[i].x = ver_wall_hit[0];
	player->ray[i].y = ver_wall_hit[1];
	player->ray[i].hitvertical = true;
	if (hor_distance < ver_distance)
	{
		player->ray[i].x = hor_wall_hit[0];
		player->ray[i].y = hor_wall_hit[1];
		player->ray[i].hitvertical = false;
	}
	player->ray[i].ray_distance = sqrt(pow(player->ray[i].x - player->x, 2)
			+ pow(player->ray[i].y - player->y, 2));
	(free(hor_wall_hit), free(ver_wall_hit));
}

void	cast_settings(t_player *player, int i)
{
	player->ray[i].ray_angle = fmod(player->ray[i].ray_angle, 2 * M_PI);
	if (player->ray[i].ray_angle < 0)
		player->ray[i].ray_angle = (2 * M_PI) + player->ray[i].ray_angle;
	player->ray[i].down_ray = player->ray[i].ray_angle < M_PI;
	player->ray[i].right_ray = player->ray[i].ray_angle < (0.5 * M_PI)
		|| player->ray[i].ray_angle > (1.5 * M_PI);
	player->ray[i].up_ray = !player->ray[i].down_ray;
	player->ray[i].left_ray = !player->ray[i].right_ray;
}

void	cast_all_rays(t_player *player)
{
	double	ray_angle;
	double	angle_increment;
	int		i;

	i = -1;
	clear_win(player);
	ray_angle = player->rotation_angle - (player->mes.fov_angle / 2);
	angle_increment = player->mes.fov_angle / player->mes.num_rays;
	while (++i < player->mes.num_rays)
	{
		player->ray[i].ray_angle = ray_angle;
		cast_settings(player, i);
		cast(player, i);
		ray_angle += angle_increment;
	}
}
