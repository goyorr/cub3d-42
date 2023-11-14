/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:03:12 by ael-kace          #+#    #+#             */
/*   Updated: 2023/10/17 21:53:15 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_map(t_map *map, char **av)
{
	map->map = NULL;
	map->map_height = 0;
	map->map_width = 0;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->f.r = -1;
	map->c.r = -1;
	if (ft_strcmp(av[1] + ft_strlen_f(av[1]) - 4, ".cub"))
		(write(2, "Error:\nWrong/no extension found!\n", 34), exit(1));
}

void	parse_map(t_map *map)
{
	check_wall_start_and_end(map);
	check_wall_on_the_map(map);
	check_player(map);
	check_any_caracter(map);
	check_empty_is_arounded(map);
	check_player_has_a_empty(map);
}

void	parcing(t_player *player, char **av)
{
	init_map(&player->map, av);
	creat_struct_map(&player->map, av);
	check_path_and_color(&player->map);
	if (!player->map.map)
		(write(2, "Error:\nNo map found!\n", 21), exit(1));
	parse_map(&player->map);
}
