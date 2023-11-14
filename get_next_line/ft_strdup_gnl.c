/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:17:27 by ael-kace          #+#    #+#             */
/*   Updated: 2023/10/16 15:30:00 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdup_gnl(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i])
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (s1[i] == '\n')
		return (str[i] = '\0', str);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
		if (s1[i] == '\n')
			return (str[i] = '\0', str);
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup_plus(const char *s1, int len, int start, int *end)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (start < *end)
	{
		str[i] = s1[start];
		start++;
		i++;
	}
	str[i] = '\0';
	if (str[0] == '\0')
		return (NULL);
	else
		return (str);
}
