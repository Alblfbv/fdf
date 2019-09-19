/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:00:53 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/19 15:28:40 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	compute_intermediate(t_point_alt *start, t_point_alt *end,\
		t_point_alt *tmp)
{
	t_color_alt	*tab;
	double		percentage;

	tab = tab_color_alt(); 
	tmp->z = tab[start->interval].altitude;
	tmp->point.color = tab[start->interval].color;
	percentage = ft_percentage((tmp->z - start->z), (end->z - start->z));
	tmp->point.x = start->point.x + percentage * (end->point.x - start->point.x);	
	tmp->point.y = start->point.y + percentage * (end->point.y - start->point.y);	
}

static int	compute_color(t_point_alt *point, int endian)
{
	t_color_alt	*tab;
	double		percentage;
	int			color1;
	int			color2;

	if (point->interval == 0)
		return (DEEP_BLUE_INT);
	if (point->interval == 5)
		return (WHITE_INT);
	tab = tab_color_alt();
	percentage = ft_percentage(point->z - tab[point->interval - 1].altitude,\
		tab[point->interval].altitude - tab[point->interval - 1].altitude);
	color1 = tab[point->interval - 1].color;
	color2 = tab[point->interval].color;
	if (endian == LITTLE)
		return (l_mlx_compute_color_little(color1, color2, percentage));
	else
		return (l_mlx_compute_color_big(color1, color2, percentage));
}

void	draw_line(t_fdf *fdf, t_point_alt *start, t_point_alt *end,\
		t_draw_mode draw_mode)
{
	t_point_alt	tmp;

	start->interval = give_interval(start->z);
	start->point.color = compute_color(start, fdf->mlx.img.endian);
	end->interval = give_interval(end->z);
	tmp.point.endian = fdf->mlx.img.endian;
	while (start->interval != end->interval)
	{
		compute_intermediate(start, end, &tmp);
		tmp.interval = start->interval + 1;
		draw_mode == xiaolin ?\
			l_mlx_draw_line_xiaolin(&fdf->mlx.img, start->point, tmp.point)\
			: l_mlx_draw_line_bresenham(&fdf->mlx.img, start->point, tmp.point);
		*start = tmp;
	}
	end->point.color = compute_color(end, fdf->mlx.img.endian);
	draw_mode == xiaolin ?\
		l_mlx_draw_line_xiaolin(&fdf->mlx.img, start->point, end->point)\
		: l_mlx_draw_line_bresenham(&fdf->mlx.img, start->point, end->point);
}

void		draw_object(t_fdf *fdf)
{
	t_point_alt	start;
	t_point_alt	end;
	int			i;

	start.point.endian = fdf->mlx.img.endian;;
	end.point.endian = fdf->mlx.img.endian;;
	i = -1;
	while (++i < fdf->nb_edges)
	{
		start.point.x = fdf->vtcs_2d[fdf->edges[i].vtx_1].x;
		start.point.y = fdf->vtcs_2d[fdf->edges[i].vtx_1].y; 
		start.z = fdf->vtcs_2d[fdf->edges[i].vtx_1].z;
		end.point.x = fdf->vtcs_2d[fdf->edges[i].vtx_2].x;
		end.point.y = fdf->vtcs_2d[fdf->edges[i].vtx_2].y;
		end.z = fdf->vtcs_2d[fdf->edges[i].vtx_2].z;
		if (start.z > end.z)
			swap_points(&start, &end);
		draw_line(fdf, &start, &end, fdf->mods.draw_mode);
	}	
}	

void	display_object_routine(t_fdf *fdf)
{
	compute_matrices(fdf);
	transform_coor(fdf);
	draw_object(fdf);
	mlx_put_image_to_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, START_X_IMG,\
		START_Y_IMG);
	ft_bzero(&fdf->mlx.img.buf, sizeof(char) * fdf->mlx.img.size_buf);
}
