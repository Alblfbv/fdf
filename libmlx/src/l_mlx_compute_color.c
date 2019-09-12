/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mlx_compute_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:23:58 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/12 18:19:55 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

char	l_mlx_compute_sub_color(char sub1, char sub2, double percentage)
{
	return ((char)((1 - percentage) * sub1 + percentage * sub2));
}

int		l_mlx_compute_color_big(int color1, int color2, double percentage)
{
	t_subcolors	subcolors;
	int			new_color;
	void		*ptr;
	unsigned char sc1;
	unsigned char sc2;
	unsigned char sc3;


	new_color = 0;
	sc1 = (unsigned char)(color2 >> 16 & 0xFF);
	sc2 = (unsigned char)(color2 >> 8 & 0xFF);
	sc3 = (unsigned char)(color2 & 0xFF);
	subcolors.red = l_mlx_compute_sub_color((char)(color1 >> 16 & 0xFF), (char)(color2 >> 16 & 0xFF), percentage);
	subcolors.green = l_mlx_compute_sub_color((color1 >> 8 & 0xFF), (color2 >> 8 & 0xFF), percentage);
	subcolors.blue = l_mlx_compute_sub_color((color1 & 0xFF), (color2 & 0xFF), percentage);
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
	subcolors.red = l_mlx_compute_sub_color((char)(color1 >> 8 & 0xFF), (char)(color2 >> 8 & 0xFF), percentage);
	subcolors.green = l_mlx_compute_sub_color((char)(color1 >> 16 & 0xFF), (char)(color2 >> 16 & 0xFF), percentage);
	subcolors.blue = l_mlx_compute_sub_color((char)(color1 >> 24 & 0xFF), (char)(color2 >> 24 & 0xFF), percentage);
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
	if (start->endian == BIG)
		return (l_mlx_compute_color_little(start->color, end->color, percentage));
	return (l_mlx_compute_color_big(start->color, end->color, percentage));
}
