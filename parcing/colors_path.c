/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:41:50 by ael-kace          #+#    #+#             */
/*   Updated: 2023/10/23 22:11:51 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_on_the_right_place_f(t_map *map, char *str, int idx)
{
	if (!str)
		return (write(2, "Error:\nInvalid color format!\n", 30), exit(1));
	if (idx == 1)
	{
		if (map->f.r != -1)
			return (write(2, "Error:\nInvalid color format!\n", 30), exit(1));
		map->f.r = ft_atoi(str);
		if (map->f.r < 0 || map->f.r > 255)
			return (write(2, "Error:\nInvalid color format!\n", 30), exit(1));
	}
	else if (idx == 2)
	{
		map->f.g = ft_atoi(str);
		if (map->f.g < 0 || map->f.g > 255)
			return (write(2, "Error:\nInvalid color format!\n", 30), exit(1));
	}
	else if (idx == 3)
	{
		map->f.b = ft_atoi(str);
		if (map->f.b < 0 || map->f.b > 255)
			return (write(2, "Error:\nInvalid color format!\n", 30), exit(1));
	}
	else
		return (write(2, "Error:\nInvalid color format!\n", 30), exit(1));
}

void	put_on_the_right_place_c(t_map *map, char *str, int idx)
{
	if (!str)
		return (write(2, "Error:\nInvalid color format!\n", 30), exit(1));
	if (idx == 1)
	{
		if (map->c.r != -1)
			return (write(2, "Error:\nInvalid color format!\n", 30), exit(1));
		map->c.r = ft_atoi(str);
		if (map->c.r < 0 || map->c.r > 255)
			return (write(2, "Error:\nInvalid color format!\n", 30), exit(1));
	}
	else if (idx == 2)
	{
		map->c.g = ft_atoi(str);
		if (map->c.g < 0 || map->c.g > 255)
			return (write(2, "Error:\nInvalid color format!\n", 30), exit(1));
	}
	else if (idx == 3)
	{
		map->c.b = ft_atoi(str);
		if (map->c.b < 0 || map->c.b > 255)
			return (write(2, "Error:\nInvalid color format!\n", 30), exit(1));
	}
	else
		return (write(2, "Error:\nInvalid color format!\n", 30), exit(1));
}

void	error_digit(char *line, int *i, int *len, int idx)
{
	if (!ft_isdigit(line[*i]))
		return (write(2, "Error:\nInvalid color format!\n", 30), exit(1));
	if (idx == 1)
	{
		(*len)++;
		(*i)++;
	}
}

void	check_v(int v)
{
	if (v != 2)
		return (write(2, "Error:\nInvalid color format!\n", 30), exit(1));
}

void	put_colors_f(t_map *map, char *line, int *i)
{
	char	*str;
	int		v;
	int		idx;
	int		len;
	int		start;

	v = 0;
	idx = 1;
	len = 0;
	while (line[*i] == ' ')
		(*i)++;
	error_digit(line, i, &len, 0);
	while (line[*i])
	{
		start = *i;
		while (line[*i] != ',' && line[*i] != '\n' && line[*i])
			error_digit(line, i, &len, 1);
		str = ft_strdup_plus(line, len, start, i);
		(put_on_the_right_place_f(map, str, idx), idx++);
		(free(str), len = 0);
		if (line[*i] == ',')
			v++;
		(*i)++;
	}
	check_v(v);
}
