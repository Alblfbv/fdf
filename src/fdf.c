/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:22:04 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/24 15:18:38 by rkirszba         ###   ########.fr       */
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

void	draw_background(void *mlx_ptr, void *win_ptr)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_HGHT)
	{
		x = -1;
		while (++x < WIN_WDTH)
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, COLOR_BG);
	}
	x = X_STR;
	y = Y_STR;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "zoom = + or -");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "X-axis rotation = 7 or 9");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "Y-axis rotation = 4 or 6");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "Z-axis rotation = 1 or 3");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "X-axis move = q or w");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "Y-axis move = a or s");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "Z-axis move = z or x");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "altitude change = 2 or 8");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "isometric proj = !");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "other proj = @");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "antialiasing mode on / off = #");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "reset = del");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "quit = esc");
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
		draw_background(fdf.mlx.mlx_ptr, fdf.mlx.win_ptr);
		display_object_routine(&fdf);
		mlx_hook(fdf.mlx.win_ptr, RED_BUTTON, 0, &handle_quit_event_mouse\
			, &fdf);
		mlx_hook(fdf.mlx.win_ptr, KEY_PRESS, 0, &handle_key_events, &fdf);
		mlx_loop(fdf.mlx.mlx_ptr);
	}
	fdf.mlx_off = 1;
	free_fdf(&fdf);
	return (ret);
}
