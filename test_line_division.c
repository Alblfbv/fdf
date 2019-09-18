/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_line_division.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:59:52 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/18 18:00:12 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"
#include "fdf.h"

// compiler command : gccflags -g -I /usr/local/include -I libft/includes -I libmlx/includes -I includes test_line_division.c src/draw_object.c src/draw_object_utils.c libft/libft.a libmlx/libmlx.a -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

int		main(void)
{
	t_fdf	fdf;
	t_point_alt start;
	t_point_alt end;
	
	fdf.mlx.mlx_ptr = mlx_init();
	fdf.mlx.win_ptr = mlx_new_window(fdf.mlx.mlx_ptr, 2560, 1440, "first try");
	fdf.mlx.img.img_ptr = mlx_new_image(fdf.mlx.mlx_ptr, 1000, 1000);
	fdf.mlx.img.buf = mlx_get_data_addr (fdf.mlx.img.img_ptr,\
		&fdf.mlx.img.bits_per_pixel, &fdf.mlx.img.size_line, &fdf.mlx.img.endian);
	fdf.mlx.img.plan.x_min = 0;
	fdf.mlx.img.plan.x_max = 1000;
	fdf.mlx.img.plan.y_min = 0;
	fdf.mlx.img.plan.y_max = 1000;
	//fdf.mods.draw_mode = xiaolin;
	fdf.mods.draw_mode = bresenham;
	end.point.y = 400;
	end.point.x = 900;
	end.z = -100;
	end.point.endian = fdf.mlx.img.endian;
	start.point.y = 400;
	start.point.x = 50;
	start.z = 200;
	start.point.endian = fdf.mlx.img.endian;
	if (start.z > end.z)
		swap_points(&start, &end);
	draw_line(&fdf, &start, &end, fdf.mods.draw_mode);
	mlx_put_image_to_window(fdf.mlx.mlx_ptr, fdf.mlx.win_ptr,\
			fdf.mlx.img.img_ptr, 780, 220);
	ft_printf("OK\n");
	mlx_loop(fdf.mlx.mlx_ptr);
	return (0);
}
