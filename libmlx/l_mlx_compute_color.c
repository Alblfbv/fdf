/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mlx_compute_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:23:58 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/11 20:08:55 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

int		l_mlx_compute_sub_color(int sub1, int sub2, double percentage)
{
	return ((1 - percent) * sub0 + percent * sub1);
}

int		l_mlx_compute_color_big(int color1, int color2, double percentage)
{
	t_subcolors	subcolors;
	int			new_color;

	new_color = 0;
	subcolors.red = compute_subcolors((color1 >> 16 & 0xFF), (color2 >> 16 & 0xFF), percentage);
	subcolors.green = compute_subcolors((color1 >> 8 & 0xFF), (color2 >> 8 & 0xFF), percentage);
	subcolors.blue = compute_subcolors((color1 & 0xFF), (color2 & 0xFF), percentage);
	ft_memcpy((char)new_color + 1, subcolors.red);
	ft_memcpy((char)new_color + 2, subcolors.green);
	ft_memcpy((char)new_color + 3, subcolors.blue);
	return (new_color);
}

int		l_mlx_compute_color_little(int color1, int color2, double percentage)
{
	t_subcolors	subcolors;
	int			new_color;

	new_color = 0;
	subcolors.red = compute_subcolors((color1 >> 8 & 0xFF), (color2 >> 8 & 0xFF), percentage);
	subcolors.green = compute_subcolors((color1 >> 16 & 0xFF), (color2 >> 16 & 0xFF), percentage);
	subcolors.blue = compute_subcolors((color1 >> 24 & 0xFF), (color2 >> 24 & 0xFF), percentage);
	ft_memcpy((char)new_color + 2, subcolors.red);
	ft_memcpy((char)new_color + 1, subcolors.green);
	ft_memcpy((char)new_color, subcolors.blue);
	return (new_color);
}

int		l_mlx_compute_color(t_point *start, t_point *end, t_point *curr)
{
	double		percentage;
	double		dx;
	double		dy;
	double		max_delta;

	dx = ft_abs_db(end->x - start->x);
	dy = ft_abs_db(end->y - start->y);
	if (dx == 0 && dy == 0)
		return (start->color);
	else
		percentage = ft_percentage(dx > dy ? ft_abs_db(curr->x - start->x)\
			: ft_abs_db(curr->y - start->y), dx > dy ? dx : dy);
	if (start->endian == LITTLE)
		return (l_mlx_compute_color_little(start->color, end->color, percentage));
	return (l_mlx_compute_color_big(start->color, end->color, percentage));
}
