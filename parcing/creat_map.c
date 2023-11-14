/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:45:14 by ael-kace          #+#    #+#             */
/*   Updated: 2023/10/23 22:11:51 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	creat_map1(t_map *map, char *line, int fd, int len)
{
	int	h;

	h = 1;
	map->map = (char **)malloc(sizeof(char *) * (len + 1));
	if (!map->map)
		return ;
	map->map_width = ft_strlen_f(line) - 1;
	while (line)
	{
		if (h == len - 1)
		{
			if (line[ft_strlen_f(line) - 1] == '\n' || !check_space(line))
				(free(line), \
					write(2, "Error:\nInvalid map!\n", 21), exit(1));
		}
		map->map[map->map_height] = ft_strdup_gnl(line);
		map->map_height++;
		(free(line), line = get_next_line(fd));
		if (map->map_width < ft_strlen_f(line) - 1)
			map->map_width = ft_strlen_f(line) - 1;
		h++;
	}
	map->map[map->map_height] = NULL;
	close(fd);
}

void	check_path_and_color(t_map *map)
{
	if (!map->no || !map->so \
		|| !map->we || !map->ea)
		(write(2, "Error:\nNo textures found!\n", 27), exit(1));
	if (map->f.r == -1 || map->c.r == -1)
		(write(2, "Error:\nWrong color format!\n", 28), exit(1));
}

void	creat_map(t_map *map, char *line, int fd, char **av)
{
	int	len;
	int	len1;

	check_path_and_color(map);
	len = 1;
	while (line)
	{
		(free(line), line = get_next_line(fd));
		len++;
	}
	if (len == 2)
		(write(2, "Error:\nNo player found\n", 24), exit(1));
	close(fd);
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	len1 = 0;
	while (line)
	{
		while (line[len1] == ' ')
			len1++;
		if (ft_isprint(line[len1]))
			return (creat_map1(map, line, fd, len));
		(free(line), line = get_next_line(fd));
		len1 = 0;
	}
}

void	creat_struct_map(t_map *map, char **av)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (perror("Error Found"), exit(1));
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] == 'N' || line[i] == 'S' \
			|| line[i] == 'W' || line[i] == 'E')
			check_path(map, line, &i);
		else if (line[i] == 'F' || line[i] == 'C')
			check_colors(line, map, &i);
		else if (ft_isprint(line[i]))
			return (creat_map(map, line, fd, av));
		free(line);
		line = get_next_line(fd);
		i = 0;
	}
}
