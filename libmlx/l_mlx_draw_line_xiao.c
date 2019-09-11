/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mlx_draw_line_xiao.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:56:02 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/11 18:02:23 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

static int	draw_limit(t_img *img, t_point *point, double gradient, int steep)
{
	int		y_pxl;
	int		x_pxl;
	int		y_limit;
	double	x_gap;
	t_point	draw_point;

	x_pxl = round(point->x);
	y_limit = point->y + gradient * (x_limit - point->x0);
	y_pxl = floor(y_limit);
	x_gap = rfpart(point->x + 0.5); //ATTENTION DISPONIBILITE FONCTION
	draw_point.color = point->color;
	draw_point.x = steep ? y_pxl : x_pxl;
	draw_point.y = steep ? x_pxl : y_pxl;
	l_mlx_write_pixel(img, draw_point, rfpart(y_limit) * x_gap);
	steep ? (draw_point.x)++ : (draw_point.y)++;
	l_mlx_write_pixel(img, draw_point, fpart(y_limit) * x_gap);
	return (x_limit);
}

static void draw_middle_point(t_img *img, t_point *point, double y_intrsct)
{
	t_point	draw_point;

	draw_point.endian = img->endian;
	draw_point.color = compute_color(point[0], point[2], point[1]);
	draw_point.x = steep ? floor(y_intrsct) : point[1].x;
	draw_point.y = steep ? point[1].x : floor(y_intrsct);
	l_mlx_write_pixel(img, draw_point, 1 - floor(y_intsct));
	steep ? (draw_point.x)++ : (draw_point_y)++;
	l_mlx_write_pixel(img, draw_point, floor(y_intsct));
}

void	swap_values(t_point *point, int steep)
{
	if (steep)
	{
		ft_swap(&point[0].x, &point[0].y)
		ft_swap(&point[2].x, &point[2].y)
	}
	if (point[0].x > point[2].x)
	{
		ft_swap(&point[0].x, &point[2].x)
		ft_swap(&point[0].y, &point[2].y)
	}
}

void	l_mlx_draw_line(t_ptrs *ptrs, t_img *img, t_point *start, t_point *end)
{
	double	gradient;
	int		steep;
	int		x_pxl_draw;
	double	y_intrsct;
	t_point	point[3];

	point[0] = *start;
	point[2] = *end;
	if (!actualize_points(&point[0], &point[2], img->plan))
		return ;
	steep = ft_abs(end->y - start->y) > ft_abs(end->x - start->x) ? 1 : 0;
	swap_values(point, steep);
	gradient = point[0].x == point[2].x ? 1 : compute_gradient(point[0], point[2])
	point[0].x = draw_limit(img, &point[0], gradient, steep) // start_limit
	if (point[0].x == end->x && point[0].y == point[2].y)
		return ;
	point[2].x = draw_limit(img, &point[2], gradient, steep) // end_limit
	y_intrsct = point[0].y + gradient * (point[0].x - start->x) + gradient;
	point[1].x = point[0].x;
	while (++(point[1].x) < point[2].x)
	{
		draw_middle_point(img, point, y_intrsct, steep)
		y_intrsct += gradient;
	}
}
