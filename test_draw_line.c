/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_draw_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:59:23 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/18 17:59:25 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libmlx.h"

// compiler command : gccflags -g -I /usr/local/include -I libft/includes -I libmlx/includes test_draw_line.c libft/libft.a libmlx/libmlx.a -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	/*
	t_point	p1;
	t_point	p2;
	t_point	p3;
	t_point	p4;
	*/
	t_point	start;
	t_point end;

	/*
	p1.x = 0;
	p1.y = 0;
	p1.color = 0xFFFFFF;
	p1.endian = 0;
	p2.x = 1000;
	p2.y = 0;
	p2.color = 0xFFFFFF;
	p2.endian = 0;
	p3.x = 0;
	p3.y = 1000;
	p3.color = 0xFFFFFF;
	p3.endian = 0;
	p4.x = 1000;
	p4.y = 1000;
	p4.color = 0xFFFFFF;
	p4.endian = 0;
	*/
	end.x = 10;
	end.y = 10;
	end.color = 0xFFFA00;
	end.endian = 0;
	start.x = 880;
	start.y = 20;
	start.color = 0xFFFA00;
	start.color = 0xF50000;
	start.endian = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 2560, 1440, "first try");
	img.img_ptr = mlx_new_image(mlx_ptr, 1000, 1000);
	img.buf = mlx_get_data_addr (img.img_ptr, &img.bits_per_pixel, &img.size_line,\
		   &img.endian);
	img.plan.x_min = 0;
	img.plan.x_max = 1000;
	img.plan.y_min = 0;
	img.plan.y_max = 1000;
	/*
	l_mlx_draw_line(&img, p2, p4);
	l_mlx_draw_line(&img, p1, p2);
	l_mlx_draw_line(&img, p1, p3);
	l_mlx_draw_line(&img, p3, p4);
	*/
	l_mlx_draw_line_xiaolin(&img, start, end);
	start.y += 100;
	end.y += 100;
	l_mlx_draw_line_bresenham(&img, start, end);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 780, 220);
	mlx_loop(mlx_ptr);
	return (0);
}
