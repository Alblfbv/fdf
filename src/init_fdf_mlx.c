/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:22:51 by allefebv          #+#    #+#             */
/*   Updated: 2019/09/26 19:23:36 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	init_mlx_img(t_fdf *fdf, t_img *img, int img_wdth, int img_hght)
{
	if (!(img->img_ptr = mlx_new_image(fdf->mlx.ptrs.mlx_ptr,\
		img_wdth, img_hght)))
		return (print_mlx_error(3));
	img->buf = mlx_get_data_addr(img->img_ptr,\
		&img->bits_per_pixel, &img->size_line, &img->endian);
	img->size_buf = img_wdth * img_hght * 4;
	img->plan.x_min = 0;
	img->plan.y_min = 0;
	img->plan.x_max = img_wdth;
	img->plan.y_max = img_hght;
	fdf->mlx_state++;
	return (0);
}

int			init_mlx(t_fdf *fdf)
{
	if (!(fdf->mlx.ptrs.mlx_ptr = mlx_init()))
		return (print_mlx_error(1));
	fdf->mlx_state++;
	if (!(fdf->mlx.ptrs.win_ptr = mlx_new_window(fdf->mlx.ptrs.mlx_ptr,\
		WIN_WDTH, WIN_HGHT, "fdf")))
		return (print_mlx_error(2));
	fdf->mlx_state++;
	if (init_mlx_img(fdf, &fdf->mlx.img, IMG_WDTH, IMG_HGHT))
		return (1);
	if (init_mlx_img(fdf, &fdf->mlx.bg_img_top, WIN_WDTH, START_Y_IMG))
		return (1);
	if (init_mlx_img(fdf, &fdf->mlx.bg_img_bot, WIN_WDTH,\
		WIN_HGHT - START_Y_IMG - IMG_HGHT))
		return (1);
	return (0);
}
