/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:00:53 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/26 19:18:53 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_object_sublines(t_fdf *fdf, t_point_alt *start,\
	t_point_alt *end, int index)
{
	t_point_alt	tmp;

	start->z = fdf->vtcs_2d[fdf->edges[index].vtx_1].z;
	end->z = fdf->vtcs_2d[fdf->edges[index].vtx_2].z;
	if (start->z > end->z)
		swap_points(start, end);
	start->interval = give_interval(fdf, start->z);
	start->point.color = compute_color(fdf, start, fdf->mlx.img.endian);
	end->interval = give_interval(fdf, end->z);
	tmp.point.endian = fdf->mlx.img.endian;
	while (start->interval != end->interval)
	{
		compute_intermediate(fdf, start, end, &tmp);
		tmp.interval = start->interval + 1;
		fdf->mods.draw_mode == xiaolin ?\
			l_mlx_draw_line_xiaolin(&fdf->mlx.img, start->point, tmp.point)\
			: l_mlx_draw_line_bresenham(&fdf->mlx.img, start->point, tmp.point);
		*start = tmp;
	}
	end->point.color = compute_color(fdf, end, fdf->mlx.img.endian);
	fdf->mods.draw_mode == xiaolin ?\
		l_mlx_draw_line_xiaolin(&fdf->mlx.img, start->point, end->point)\
		: l_mlx_draw_line_bresenham(&fdf->mlx.img, start->point, end->point);
}

void		draw_object_singleline(t_fdf *fdf, t_point_alt *start,\
	t_point_alt *end)
{
	start->point.color = l_mlx_sub_to_color(fdf->wireframe_col,\
		fdf->mlx.img.endian);
	end->point.color = start->point.color;
	fdf->mods.draw_mode == xiaolin ?\
		l_mlx_draw_line_xiaolin(&fdf->mlx.img, start->point, end->point)\
		: l_mlx_draw_line_bresenham(&fdf->mlx.img, start->point, end->point);
}

void		draw_object(t_fdf *fdf)
{
	t_point_alt	start;
	t_point_alt	end;
	int			i;

	start.point.endian = fdf->mlx.img.endian;
	end.point.endian = fdf->mlx.img.endian;
	i = -1;
	while (++i < fdf->nb_edges)
	{
		start.point.x = fdf->vtcs_2d[fdf->edges[i].vtx_1].x;
		start.point.y = fdf->vtcs_2d[fdf->edges[i].vtx_1].y;
		end.point.x = fdf->vtcs_2d[fdf->edges[i].vtx_2].x;
		end.point.y = fdf->vtcs_2d[fdf->edges[i].vtx_2].y;
		if (fdf->mods.color_mode == unicolor)
			draw_object_singleline(fdf, &start, &end);
		else
			draw_object_sublines(fdf, &start, &end, i);
	}
}

void		display_object_routine(t_fdf *fdf)
{
	compute_tmp_matrix(fdf);
	transform_coor(fdf);
	if (fdf->mods.col_updt)
	{
		draw_background(fdf);
		mlx_put_image_to_window(fdf->mlx.ptrs.mlx_ptr, fdf->mlx.ptrs.win_ptr,\
			fdf->mlx.bg_img_top.img_ptr, 0, 0);
		mlx_put_image_to_window(fdf->mlx.ptrs.mlx_ptr, fdf->mlx.ptrs.win_ptr,\
			fdf->mlx.bg_img_bot.img_ptr, 0, START_Y_IMG + IMG_HGHT + 1);
		fdf->mods.col_updt = 0;
		ft_bzero(fdf->mlx.bg_img_top.buf,\
			sizeof(char) * fdf->mlx.bg_img_top.size_buf);
		ft_bzero(fdf->mlx.bg_img_bot.buf,\
			sizeof(char) * fdf->mlx.bg_img_bot.size_buf);
	}
	draw_object(fdf);
	mlx_put_image_to_window(fdf->mlx.ptrs.mlx_ptr, fdf->mlx.ptrs.win_ptr,\
		fdf->mlx.img.img_ptr, START_X_IMG, START_Y_IMG);
	draw_menu(&fdf->mlx.ptrs);
	ft_bzero(fdf->mlx.img.buf, sizeof(char) * fdf->mlx.img.size_buf);
}
