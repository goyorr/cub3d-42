/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:22:50 by ael-kace          #+#    #+#             */
/*   Updated: 2023/10/23 22:13:43 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 && s2)
		return (s2);
	if (s1 && !s2)
		return (s1);
	if (s1 && s2)
	{
		res = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1));
		if (!res)
			return (NULL);
		i = -1;
		j = -1;
		while (s1[++i])
			res[i] = s1[i];
		while (s2[++j])
			res[i + j] = s2[j];
		res[i + j] = '\0';
		return (free(s1), free(s2), res);
	}
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(const char *s, char c)
{
	int		i;

	i = -1;
	if (!s)
		return (0);
	while (s && s[++i])
		if (s[i] == c)
			return (1);
	return (0);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*s2;

	i = ft_strlen(s1);
	s2 = malloc(sizeof(char *) * (i + 1));
	if (!s2)
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = 0;
	return (s2);
}
