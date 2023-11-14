/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:31:28 by ael-kace          #+#    #+#             */
/*   Updated: 2023/10/28 22:42:54 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_array(int *x, int *y, mlx_texture_t *side, int **pixel_holder)
{
	static int	pixel;

	if (pixel >= 64 * 64 * 4)
		pixel = 0;
	pixel_holder[*y][*x] = (side->pixels[pixel] << 24)
		| (side->pixels[pixel + 1] << 16)
		| (side->pixels[pixel + 2] << 8)
		| side->pixels[pixel + 3];
	pixel += 4;
}

int	**fill_color_array(mlx_texture_t *side)
{
	int	y;
	int	x;
	int	**pixel_holder;

	pixel_holder = (int **)malloc(64 * sizeof(int *));
	if (!pixel_holder)
		return (0);
	y = -1;
	while (++y < 64)
	{
		pixel_holder[y] = (int *)malloc(sizeof(int) * 64);
		if (!pixel_holder[y])
			return (0);
	}
	y = -1;
	while (++y < 64)
	{
		x = -1;
		while (++x < 64)
			fill_array(&x, &y, side, pixel_holder);
	}
	return (pixel_holder);
}
