/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:31:58 by ael-kace          #+#    #+#             */
/*   Updated: 2023/10/27 22:00:47 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_d(t_player *player, mlx_key_data_t keydata)
{
	if (keydata.action == MLX_PRESS)
		player->side_direction = 1;
	else if (keydata.action == MLX_RELEASE)
		player->side_direction = 0;
}

void	key_func(mlx_key_data_t keydata, void *param)
{
	t_player	*player;

	player = param;
	if (keydata.key == MLX_KEY_W)
		key_w(player, keydata);
	if (keydata.key == MLX_KEY_S)
		key_s(player, keydata);
	if (keydata.key == MLX_KEY_LEFT)
		key_left(player, keydata);
	if (keydata.key == MLX_KEY_RIGHT)
		key_right(player, keydata);
	if (keydata.key == MLX_KEY_A)
		key_a(player, keydata);
	if (keydata.key == MLX_KEY_D)
		key_d(player, keydata);
	if (keydata.key == MLX_KEY_ESCAPE)
		exit (0);
}
