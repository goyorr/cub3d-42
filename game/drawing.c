/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:31:40 by ael-kace          #+#    #+#             */
/*   Updated: 2023/10/23 22:45:33 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_mini_map_border(t_player *player)
{
	int	ymini;
	int	xmini;

	ymini = -1;
	while (++ymini < 220)
	{
		xmini = -1;
		while (++xmini < 220)
			mlx_put_pixel(player->img.img, xmini, ymini, YELLOW);
	}
}

void	draw_mini_map(t_player *player)
{
	int	y;
	int	x;
	int	ymini;
	int	xmini;

	ymini = 9;
	y = player->y - 100;
	while (++ymini < 210)
	{
		x = player->x - 100 - 1;
		xmini = 9;
		while (++xmini < 210)
		{
			if (y >= 10 && ++x >= 10)
			{
				if (has_wall(player, x, y))
					mlx_put_pixel(player->img.img, xmini, ymini, RED);
				else
					mlx_put_pixel(player->img.img, xmini, ymini, GREY);
			}
			else
				mlx_put_pixel(player->img.img, xmini, ymini, BLACK);
		}
		y++;
	}
}

void	clear_win(t_player *player)
{
	if (player->img.img)
		mlx_delete_image(player->img.mlx, player->img.img);
	player->img.img = mlx_new_image(player->img.mlx,
			player->mes.win_width, player->mes.win_height);
}

void	draw_rectangles(t_player *player, int x, int **texture)
{
	int	y;
	int	y1;

	y1 = (player->mes.win_height / 2) - (player->mes.wall_strip_height / 2);
	y = -1;
	while (++y < player->mes.win_height)
	{
		if (y < y1)
			mlx_put_pixel(player->img.img, x, y, player->color.ceiling_color);
		else if (y < y1 + player->mes.wall_strip_height)
			mlx_put_pixel(player->img.img, x, y,
				texture_mapping(player, texture, y, x));
		else
			mlx_put_pixel(player->img.img, x, y, player->color.floor_color);
	}
}

void	draw_player(t_player *player)
{
	int	i;
	int	j;

	i = -5;
	if (!player_movement(player))
		return ;
	cast_all_rays(player);
	render_projected_walls(player);
	draw_mini_map_border(player);
	draw_mini_map(player);
	while (i++ < 5)
	{
		j = -5;
		while (j++ < 5)
			mlx_put_pixel(player->img.img, 110 - j,
				110 - i, GREEN);
	}
}
