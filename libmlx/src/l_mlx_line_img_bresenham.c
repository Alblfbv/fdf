/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mlx_line_img_bresenham.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:18:32 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/26 18:08:39 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

static void	draw_points(t_img *img, t_point *start, t_point *end, int steep)
{
	int		dx;
	int		dy;
	int		error;
	t_point	draw_point;

	error = (int)end->x - (int)start->x;
	dx = error * 2;
	dy = ((int)end->y - (int)start->y) * 2;
	draw_point.endian = img->endian;
	draw_point.x = (int)start->x - 1;
	draw_point.y = start->y;
	while (++(draw_point.x) <= end->x)
	{
		draw_point.color = l_mlx_compute_color(start, end, &draw_point);
		if (steep)
			ft_swap_db(&draw_point.x, &draw_point.y);
		l_mlx_write_pixel(img, &draw_point);
		if (steep)
			ft_swap_db(&draw_point.x, &draw_point.y);
		if ((error = error - (dy > 0 ? dy : -dy)) <= 0)
		{
			draw_point.y += (dy > 0 ? 1 : -1);
			error = error + dx;
		}
	}
}

void		l_mlx_draw_line_bresenham(t_img *img, t_point start, t_point end)
{
	int	steep;

	img->size_buf = img->size_line * img->plan.y_max;
	if (!(l_mlx_actualize_points(&start, &end, &img->plan)))
		return ;
	start.x = round(start.x);
	start.y = round(start.y);
	end.x = round(end.x);
	end.y = round(end.y);
	steep = (fabs(end.y - start.y) > fabs(end.x - start.x) ? 1 : 0);
	if (steep)
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
	draw_points(img, &start, &end, steep);
}
