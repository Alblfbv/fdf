/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mlx_line_img_xiao.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:56:02 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/26 18:16:51 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

static void	draw_limit(t_img *img, t_point *point, t_draw_line *line, int limit)
{
	int		y_pxl;
	int		x_pxl;
	double	y_limit;
	double	x_gap;
	t_point	draw_point;

	x_pxl = round(point->x);
	y_limit = point->y + line->gradient * (x_pxl - point->x);
	y_pxl = floor(y_limit);
	x_gap = ft_rfpart(point->x + 0.5);
	draw_point.color = point->color;
	draw_point.x = line->steep ? y_pxl : x_pxl;
	draw_point.y = line->steep ? x_pxl : y_pxl;
	draw_point.endian = img->endian;
	l_mlx_write_pixel_pct(img, &draw_point, ft_rfpart(y_limit) * x_gap);
	line->steep ? (draw_point.x)++ : (draw_point.y)++;
	l_mlx_write_pixel_pct(img, &draw_point, ft_fpart(y_limit) * x_gap);
	if (limit == START)
		line->x_pxl_start = x_pxl;
	else
		line->x_pxl_end = x_pxl;
}

static void	draw_middle_points(t_img *img, t_point *start, t_point *end,\
	t_draw_line *line)
{
	t_point	draw_point;
	int		x_pxl_mid;

	draw_point.endian = img->endian;
	x_pxl_mid = line->x_pxl_start;
	while (++x_pxl_mid <= line->x_pxl_end)
	{
		draw_point.x = x_pxl_mid;
		draw_point.y = floor(line->y_intrsct);
		draw_point.color = l_mlx_compute_color(start, end, &draw_point);
		if (line->steep)
			ft_swap_db(&draw_point.x, &draw_point.y);
		l_mlx_write_pixel_pct(img, &draw_point, ft_rfpart(line->y_intrsct));
		line->steep ? (draw_point.x)++ : (draw_point.y)++;
		l_mlx_write_pixel_pct(img, &draw_point, ft_fpart(line->y_intrsct));
		line->y_intrsct += line->gradient;
	}
}

void		l_mlx_draw_line_xiaolin(t_img *img, t_point start, t_point end)
{
	t_draw_line	line;

	img->size_buf = img->size_line * img->plan.y_max;
	if (!l_mlx_actualize_points(&start, &end, &img->plan))
		return ;
	line.steep = (fabs(end.y - start.y) > fabs(end.x - start.x) ? 1 : 0);
	if (line.steep)
	{
		ft_swap_db(&start.x, &start.y);
		ft_swap_db(&end.x, &end.y);
	}
	if (start.x > end.x)
	{
		ft_swap_db(&start.x, &end.x);
		ft_swap_db(&start.y, &end.y);
		ft_swap_int(&start.color, &end.color);
	}
	line.gradient = (start.x == end.x) ? 1\
		: l_mlx_compute_gradient(&start, &end);
	draw_limit(img, &start, &line, START);
	line.y_intrsct = start.y + line.gradient * (line.x_pxl_start - start.x + 1);
	if (start.x == end.x && start.y == end.y)
		return ;
	draw_limit(img, &end, &line, END);
	draw_middle_points(img, &start, &end, &line);
}
