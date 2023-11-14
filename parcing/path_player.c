/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:39:43 by ael-kace          #+#    #+#             */
/*   Updated: 2023/10/23 21:30:30 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	north_path(t_map *map, char *str, int *i)
{
	if (map->no)
		return (write(2, "Error:\nPath redefined!\n", 24), exit(1));
	while (str[*i] <= ' ')
		(*i)++;
	map->no = ft_strdup_gnl(str + *i);
	if (map->no[0] == '\0')
		return (write(2, "Error:\nMissing north texture path!\n", 36), exit(1));
}

void	south_path(t_map *map, char *str, int *i)
{
	if (map->so)
		return (write(2, "Error:\nPath redefined!\n", 24), exit(1));
	while (str[*i] <= ' ')
		(*i)++;
	map->so = ft_strdup_gnl(str + *i);
	if (map->so[0] == '\0')
		return (write(2, "Error:\nMissing south texture path!\n", 36), exit(1));
}

void	west_path(t_map *map, char *str, int *i)
{
	if (map->we)
		return (write(2, "Error:\nPath redefined!\n", 24), exit(1));
	while (str[*i] <= ' ')
		(*i)++;
	map->we = ft_strdup_gnl(str + *i);
	if (map->we[0] == '\0')
		return (write(2, "Error:\nMissing west texture path!\n", 35), exit(1));
}

void	east_path(t_map *map, char *str, int *i)
{
	if (map->ea)
		return (write(2, "Error:\nPath redefined!\n", 24), exit(1));
	while (str[*i] <= ' ')
		(*i)++;
	map->ea = ft_strdup_gnl(str + *i);
	if (map->ea[0] == '\0')
		return (write(2, "Error:\nMissing east texture path!\n", 35), exit(1));
}

void	check_path(t_map *map, char *line, int *i)
{
	if (line[*i] == 'N' && line[*i + 1] == 'O' && line[*i + 2] <= ' ')
	{
		*i += 2;
		north_path(map, line, i);
	}
	else if (line[*i] == 'S' && line[*i + 1] == 'O' && line[*i + 2] <= ' ')
	{
		*i += 2;
		south_path(map, line, i);
	}
	else if (line[*i] == 'W' && line[*i + 1] == 'E' && line[*i + 2] <= ' ')
	{
		*i += 2;
		west_path(map, line, i);
	}
	else if (line[*i] == 'E' && line[*i + 1] == 'A' && line[*i + 2] <= ' ')
	{
		*i += 2;
		east_path(map, line, i);
	}
	else
		(write(2, "Error:\nWrong type identifier!\n", 31), exit(1));
}
