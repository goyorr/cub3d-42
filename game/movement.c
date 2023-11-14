/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:32:12 by ael-kace          #+#    #+#             */
/*   Updated: 2023/10/28 02:08:45 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	wall_collision(t_player *player, double x, double y)
{
	int	i;
	int	j;
	int	i_r;
	int	i_l;

	if (x < 0 || x > player->mes.map_num_colms * 64 || y < 0
		|| y > player->mes.map_num_rows * 64)
		return (1);
	i = floor(y / player->mes.tile_size);
	j = floor(x / player->mes.tile_size);
	i_r = (int)((x + 5) / player->mes.tile_size);
	i_l = (int)((x - 5) / player->mes.tile_size);
	if (i >= player->map.map_height || j >= player->map.map_width)
		return (1);
	if (i_l >= 0 && player->map.map[i][i_l] == '1')
		return (1);
	if (i_r < (player->mes.win_width / 64) && player->map.map[i][i_r] == '1')
		return (1);
	if (i_l >= 0 && player->map.map[i][i_l] == '1' && \
		player->map.map[i][j] == '1')
		return (1);
	if (i_r < (player->mes.win_width / 64) && player->map.map[i][i_r] == '1' \
		&& player->map.map[i][j] == '1')
		return (1);
	return (player->map.map[i][j] == '1');
}

int	has_wall(t_player *player, double x, double y)
{
	int	i;
	int	j;

	if (x < 0 || x > player->mes.map_num_colms * 64 || y < 0
		|| y > player->mes.map_num_rows * 64)
		return (1);
	i = floor(y / player->mes.tile_size);
	j = floor(x / player->mes.tile_size);
	if (i >= player->map.map_height || j >= player->map.map_width)
		return (1);
	return (player->map.map[i][j] == '1');
}

int	player_movement(t_player *player)
{
	int	move_step;
	int	x;
	int	y;

	player->rotation_angle += player->turn_direction * player->rotation_speed;
	move_step = player->move_speed * player->walk_direction;
	if (wall_collision(player, player->x + cos(player->rotation_angle) * \
		move_step, player->y + sin(player->rotation_angle) * move_step))
		return (0);
	player->x += cos(player->rotation_angle) * move_step;
	player->y += sin(player->rotation_angle) * move_step;
	move_step = player->move_speed * player->side_direction;
	x = cos(player->rotation_angle + M_PI / 2) * move_step;
	y = sin(player->rotation_angle + M_PI / 2) * move_step;
	if (wall_collision(player, player->x + x, player->y + y))
		return (0);
	player->x += x;
	player->y += y;
	return (1);
}
