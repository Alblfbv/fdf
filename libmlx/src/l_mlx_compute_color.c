/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mlx_compute_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:23:58 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/14 17:07:56 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

unsigned char	l_mlx_compute_sub_color(unsigned char sub1, unsigned char sub2, double percentage)
{
	return ((unsigned char)((1 - percentage) * sub1 + percentage * sub2));
}

int		l_mlx_compute_color_big(int color1, int color2, double percentage)
{
	t_subcolors	subcolors;
	int			new_color;
	void		*ptr;

	new_color = 0;
	subcolors.red = l_mlx_compute_sub_color((unsigned char)(color1 >> 16 & 0xFF), (unsigned char)(color2 >> 16 & 0xFF), percentage);
	subcolors.green = l_mlx_compute_sub_color((unsigned char)(color1 >> 8 & 0xFF), (unsigned char)(color2 >> 8 & 0xFF), percentage);
	subcolors.blue = l_mlx_compute_sub_color((unsigned char)(color1 & 0xFF), (unsigned char)(color2 & 0xFF), percentage);
	ptr = &new_color;
	ft_memcpy(ptr + 1, &(subcolors.red), sizeof(char));
	ft_memcpy(ptr + 2, &(subcolors.green), sizeof(char));
	ft_memcpy(ptr + 3, &(subcolors.blue), sizeof(char));
	return (new_color);
}

int		l_mlx_compute_color_little(int color1, int color2, double percentage)
{
	t_subcolors	subcolors;
	int			new_color;
	void		*ptr;

	new_color = 0;
	subcolors.red = l_mlx_compute_sub_color((unsigned char)(color1 >> 16 & 0xFF), (unsigned char)(color2 >> 16 & 0xFF), percentage);
	subcolors.green = l_mlx_compute_sub_color((unsigned char)(color1 >> 8 & 0xFF), (unsigned char)(color2 >> 8 & 0xFF), percentage);
	subcolors.blue = l_mlx_compute_sub_color((unsigned char)(color1 & 0xFF), (unsigned char)(color2 & 0xFF), percentage);
	ptr = &new_color;
	ft_memcpy(ptr + 2, &(subcolors.red), sizeof(char));
	ft_memcpy(ptr + 1, &(subcolors.green), sizeof(char));
	ft_memcpy(ptr, &(subcolors.blue), sizeof(char));
	return (new_color);
}

int		l_mlx_compute_color(t_point *start, t_point *end, t_point *curr)
{
	double		percentage;
	double		dx;
	double		dy;

	dx = fabs(end->x - start->x);
	dy = fabs(end->y - start->y);
	if (dx == 0 && dy == 0)
		return (start->color);
	else
		percentage = ft_percentage(dx > dy ? fabs(curr->x - start->x)\
			: fabs(curr->y - start->y), dx > dy ? dx : dy);
	if (start->endian == LITTLE)
		return (l_mlx_compute_color_little(start->color, end->color, percentage));
	return (l_mlx_compute_color_big(start->color, end->color, percentage));
}
