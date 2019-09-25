/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:22:04 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/25 20:23:21 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
static void	display_tabs(t_fdf *fdf)
{
	int		i = -1;
	ft_printf("----- tab 3d --------\n");
	while (++i < fdf->nb_vertices)
	{
		ft_printf("---%d---\n", i);
		ft_printf("x = %lf | y = %lf | z = %lf\n", fdf->vtcs_3d[i].x, fdf->vtcs_3d[i].y, fdf->vtcs_3d[i].z);
	}
	i = -1;
	ft_printf("-----tab edges-----\n");
	while (++i < fdf->nb_edges)
	{
		ft_printf("--- %d ---\n", i);
		ft_printf("vtc1 = %d | vtc2 = %d\n", fdf->edges[i].vtx_1, fdf->edges[i].vtx_2);
	}
}
*/

static void	draw_img_border(t_fdf *fdf, int wire_color)
{
	t_point	top_left;
	t_point top_right;
	t_point	bot_left;
	t_point	bot_right;

	top_left.x = START_X_IMG - 1;
	top_left.y = START_Y_IMG - 1;
	top_left.color = wire_color;
	top_left.endian = fdf->mlx.img.endian;
	top_right.x = START_X_IMG + IMG_WDTH;
	top_right.y = START_Y_IMG - 1;
	top_right.color = wire_color;
	top_right.endian = fdf->mlx.img.endian;
	bot_left.x = START_X_IMG - 1;
	bot_left.y = 0;
	bot_left.color = wire_color;
	bot_left.endian = fdf->mlx.img.endian;
	bot_right.x = START_X_IMG + IMG_WDTH;
	bot_right.y = 0;
	bot_right.color = wire_color;
	bot_right.endian = fdf->mlx.img.endian;
	l_mlx_draw_line_bresenham(&fdf->mlx.bg_img_top, top_left, top_right);
	l_mlx_draw_line_bresenham(&fdf->mlx.bg_img_bot, bot_left, bot_right);
	//l_mlx_draw_line_bresenham(&fdf->mlx.bg_img, top_left, bot_left);
	//l_mlx_draw_line_bresenham(&fdf->mlx.bg_img, top_right, bot_right);
}

void	draw_background(t_fdf *fdf)
{
	int	x;
	int	y;
	int	background_color;
	int	wire_color;
	t_point	point;

	wire_color = l_mlx_sub_to_color(fdf->wireframe_col, fdf->mlx.img.endian);
	background_color = fdf->mlx.img.endian == LITTLE ?\
		l_mlx_compute_color_little(0, wire_color, 0.15) :\
		l_mlx_compute_color_big(0, wire_color, 0.15);
	y = -1;
	point.color = background_color;
	while (++y < START_Y_IMG)
	{
		x = -1;
		point.y = y;
		while (++x < WIN_WDTH)
		{
			point.x = x;
			l_mlx_write_pixel(&fdf->mlx.bg_img_top, &point);
		}
	}
	y = -1;
	while (++y < WIN_HGHT - START_Y_IMG - IMG_HGHT)
	{
		x = -1;
		point.y = y;
		while (++x < WIN_WDTH)
		{
			point.x = x;
			l_mlx_write_pixel(&fdf->mlx.bg_img_bot, &point);
		}
	}
	draw_img_border(fdf, wire_color);
}

int		main(int ac, char **av)
{
	t_fdf	fdf;
	int		ret;
	int		fd;

	if (ac != 2)
		return (print_usage());
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (print_sys_error(errno));
	ft_bzero(&fdf, sizeof(t_fdf));
	ret = parse_map(&fdf, fd);
	if (!ret)
		ret = init_fdf(&fdf);
//	if (!ret)
//		display_tabs(&fdf);
	if (!ret)
	{
		display_object_routine(&fdf);
		mlx_hook(fdf.mlx.ptrs.win_ptr, RED_BUTTON, 0, &handle_quit_event_mouse\
			, &fdf);
		mlx_hook(fdf.mlx.ptrs.win_ptr, KEY_PRESS, 0, &handle_key_events, &fdf);
		mlx_loop(fdf.mlx.ptrs.mlx_ptr);
	}
	fdf.mlx_off = 1;
	free_fdf(&fdf);
	return (ret);
}
