/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mlx_write_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:30:24 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/26 18:37:53 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** only works for bpp = 32
** endianess already taken care of
*/

#include "libmlx.h"

void	l_mlx_write_pixel(t_img *img, t_point *point)
{
	int	buf_pos;

	buf_pos = point->y * img->size_line + point->x * 4;
	if (l_mlx_is_on_plan(point, &img->plan) && buf_pos < img->size_buf)
		ft_memcpy((void*)(img->buf + buf_pos), (void*)(&point->color),\
			sizeof(int));
}

void	l_mlx_write_pixel_pct(t_img *img, t_point *point, double percentage)
{
	t_point	draw_point;

	draw_point = *point;
	percentage = sqrt(percentage);
	if (img->endian == BIG)
		draw_point.color = l_mlx_compute_color_big(0, point->color, percentage);
	else
		draw_point.color =\
			l_mlx_compute_color_little(0, point->color, percentage);
	l_mlx_write_pixel(img, &draw_point);
}
