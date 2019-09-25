/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:22:04 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/25 15:37:57 by allefebv         ###   ########.fr       */
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

static void	draw_img_border(t_mlx *mlx)
{
	t_point	top_left;
	t_point top_right;
	t_point	bot_left;
	t_point	bot_right;

	top_left.x = START_X_IMG - 1;
	top_left.y = START_Y_IMG - 1;
	top_left.color = 0x00f9ff;
	top_left.endian = mlx->img.endian;
	top_right.x = START_X_IMG + IMG_WDTH;
	top_right.y = START_Y_IMG - 1;
	top_right.color = 0x00f9ff;
	top_right.endian = mlx->img.endian;
	bot_left.x = START_X_IMG - 1;
	bot_left.y = START_Y_IMG + IMG_HGHT;
	bot_left.color = 0x00f9ff;
	bot_left.endian = mlx->img.endian;
	bot_right.x = START_X_IMG + IMG_WDTH;
	bot_right.y = START_Y_IMG + IMG_HGHT;
	bot_right.color = 0x00f9ff;
	bot_right.endian = mlx->img.endian;
	l_mlx_line_win_bresenham(&mlx->ptrs, top_left, top_right);
	l_mlx_line_win_bresenham(&mlx->ptrs, bot_left, bot_right);
	l_mlx_line_win_bresenham(&mlx->ptrs, top_left, bot_left);
	l_mlx_line_win_bresenham(&mlx->ptrs, top_right, bot_right);
}

void	draw_background(t_mlx *mlx)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_HGHT)
	{
		x = -1;
		while (++x < WIN_WDTH)
			mlx_pixel_put(mlx->ptrs.mlx_ptr, mlx->ptrs.win_ptr, x, y, COLOR_BG);
	}
	draw_img_border(mlx);
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
		draw_background(&fdf.mlx);
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
