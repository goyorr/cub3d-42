/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:32:07 by ael-kace          #+#    #+#             */
/*   Updated: 2023/10/22 17:32:09 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_right(t_player *player, mlx_key_data_t keydata)
{
	if (keydata.action == MLX_PRESS)
		player->turn_direction = 1;
	else if (keydata.action == MLX_RELEASE)
		player->turn_direction = 0;
}

void	key_left(t_player *player, mlx_key_data_t keydata)
{
	if (keydata.action == MLX_PRESS)
		player->turn_direction = -1;
	else if (keydata.action == MLX_RELEASE)
		player->turn_direction = 0;
}

void	key_w(t_player *player, mlx_key_data_t keydata)
{
	if (keydata.action == MLX_PRESS)
		player->walk_direction = 1;
	else if (keydata.action == MLX_RELEASE)
		player->walk_direction = 0;
}

void	key_s(t_player *player, mlx_key_data_t keydata)
{
	if (keydata.action == MLX_PRESS)
		player->walk_direction = -1;
	else if (keydata.action == MLX_RELEASE)
		player->walk_direction = 0;
}

void	key_a(t_player *player, mlx_key_data_t keydata)
{
	if (keydata.action == MLX_PRESS)
		player->side_direction = -1;
	else if (keydata.action == MLX_RELEASE)
		player->side_direction = 0;
}
