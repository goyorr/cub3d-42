/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kach <zel-kach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:31:17 by zel-kach          #+#    #+#             */
/*   Updated: 2023/11/02 02:32:30 by zel-kach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	moving_curs(t_player *player)
{
	static int	mx;
	static int	my;
	static int	last_position;
	int			direction;

	last_position = mx;
	mlx_set_cursor_mode(player->img.mlx, MLX_MOUSE_HIDDEN);
	if (mx >= 2015 || mx <= -544)
		mlx_set_mouse_pos(player->img.mlx, 500, my);
	mlx_get_mouse_pos(player->img.mlx, &mx, &my);
	if (last_position != mx)
	{
		if (mx > last_position)
			direction = 2;
		else 
			direction = -2;
		player->rotation_angle += direction * 2 * (M_PI / 180);
	}
}

void	loop(void *d)
{
	t_player	*player;

	player = (t_player *)d;
	moving_curs(player);
	draw_player(player);
	mlx_image_to_window(player->img.mlx, player->img.img, 0, 0);
}
