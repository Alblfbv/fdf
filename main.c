/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:02:13 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/12 19:23:04 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libmlx.h"

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_point	p1;
	t_point	p2;

	p1.x = -300;
	p1.y = 32;
	p1.color = 0x283AFF;
	p1.endian = LITTLE;
	p2.x = 40;
	p2.y = 70;
	p2.color = 0xFF3B25;
	p2.endian = LITTLE;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 2560, 1440, "first try");
	img.img_ptr = mlx_new_image(mlx_ptr, 500, 500);
	img.buf = mlx_get_data_addr (img.img_ptr, &img.bits_per_pixel, &img.size_line,\
		   &img.endian);
	img.plan.x_min = 0;
	img.plan.x_max = 500;
	img.plan.y_min = 0;
	img.plan.y_max = 500;
	l_mlx_draw_line(&img, p1, p2);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 200, 200);
	mlx_loop(mlx_ptr);
	return (0);
}
