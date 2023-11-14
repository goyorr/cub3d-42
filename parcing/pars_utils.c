/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:58:02 by elkacem           #+#    #+#             */
/*   Updated: 2023/10/21 10:50:22 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_space(char *str)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			space++;
		i++;
	}
	if (ft_strlen_f(str) == space)
		return (0);
	else
		return (1);
}

int	caractere_map(int c)
{
	if (c == '1' || c == '0' || c == ' ' \
		|| c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	caractere_map_1(int c)
{
	if (c == '1' || c == '0' \
		|| c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	caractere_map_2(int c)
{
	if (c == '1' || c == '0')
		return (1);
	return (0);
}

void	check_player(t_map *map)
{
	int	h;
	int	w;
	int	p;

	h = 0;
	w = 0;
	p = 0;
	while (h < map->map_height)
	{
		while (map->map[h][w])
		{
			if (map->map[h][w] == 'N' || map->map[h][w] == 'W' \
				|| map->map[h][w] == 'E' || map->map[h][w] == 'S')
				p++;
			w++;
		}
		w = 0;
		h++;
	}
	if (p != 1)
		(write(2, "Error:\nInvalid amount of players\n", 34), exit(1));
}
