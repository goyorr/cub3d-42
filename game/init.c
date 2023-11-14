/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:31:46 by ael-kace          #+#    #+#             */
/*   Updated: 2023/10/27 21:29:24 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	find_neemo(t_player *player)
{
	int	x;
	int	y;

	x = -1;
	while (++x < player->mes.map_num_rows)
	{
		y = -1;
		while (player->map.map[x][++y])
		{
			if (ft_isalpha(player->map.map[x][y]))
			{
				player->x = (y * player->mes.tile_size) + 32;
				player->y = (x * player->mes.tile_size) + 32;
				if (player->map.map[x][y] == 'N')
					player->rotation_angle = M_PI * 1.5;
				else if (player->map.map[x][y] == 'S')
					player->rotation_angle = M_PI / 2;
				else if (player->map.map[x][y] == 'E')
					player->rotation_angle = 0;
				else if (player->map.map[x][y] == 'W')
					player->rotation_angle = M_PI;
				return ;
			}
		}
	}
}

void	init_player(t_player *player)
{
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->side_direction = 0;
	player->move_speed = 3.0;
	player->rotation_speed = 2 * (M_PI / 180);
	find_neemo(player);
}

void	init_mesurments(t_player *player)
{
	player->mes.tile_size = 64;
	player->mes.map_num_rows = player->map.map_height;
	player->mes.map_num_colms = player->map.map_width;
	player->mes.win_width = 1472;
	player->mes.win_height = 1024;
	player->mes.fov_angle = 60 * (M_PI / 180);
	player->mes.num_rays = player->mes.win_width;
	player->ray = malloc(player->mes.num_rays * sizeof(t_rays));
	if (!player->ray)
		(write(2, "Error:\nProblem allocating memory!\n", 35), exit(1));
}

void	init_textures(t_player *player)
{
	mlx_texture_t	*no_side;
	mlx_texture_t	*we_side;
	mlx_texture_t	*ea_side;
	mlx_texture_t	*so_side;

	no_side = mlx_load_png(player->map.no);
	ea_side = mlx_load_png(player->map.ea);
	so_side = mlx_load_png(player->map.so);
	we_side = mlx_load_png(player->map.we);
	if (!no_side || !ea_side || !so_side || !we_side)
		(write(2, "Error:\nProblem loading textures!\n", 34), exit(1));
	player->textures.no_side = fill_color_array(no_side);
	player->textures.ea_side = fill_color_array(ea_side);
	player->textures.so_side = fill_color_array(so_side);
	player->textures.we_side = fill_color_array(we_side);
	mlx_delete_texture(no_side);
	mlx_delete_texture(ea_side);
	mlx_delete_texture(so_side);
	mlx_delete_texture(we_side);
}

void	init_color(t_player *player)
{
	player->color.ceiling_color = (player->map.c.r << 24)
		| (player->map.c.g << 16)
		| (player->map.c.b << 8)
		| 255;
	player->color.floor_color = (player->map.f.r << 24)
		| (player->map.f.g << 16)
		| (player->map.f.b << 8)
		| 255;
}
