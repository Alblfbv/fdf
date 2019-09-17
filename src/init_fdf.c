/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:37:17 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/17 09:39:18 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	init_mlx(t_fdf *fdf)
{
	if (!(fdf->mlx.mlx_ptr = mlx_init()))
		return (print_mlx_error(1));
	if (!(fdf->mlx.win_ptr = mlx_new_window(fdf->mlx.mlx_ptr, WIN_WDTH,\
				WIN_HGHT, "fdf")))
		return (print_mlx_error(2));	
	if (!(fdf->mlx.img.img_ptr = mlx_new_image(fdf->mlx.mlx_ptr,\
				IMG_WDTH, IMG_HGHT)))
		return (print_mlx_error(3));
	fdf->mlx.img.buf = mlx_get_data_addr (fdf->mlx.img.img_ptr,\
		&fdf->mlx.img.bits_per_pixel, &fdf->mlx.img.size_line,\
		&fdf->mlx.img.endian);
	fdf->mlx.img.plan.x_min = 0;
	fdf->mlx.img.plan.x_max = IMG_WDTH;
	fdf->mlx.img.plan.y_min = 0;
	fdf->mlx.img.plan.y_max = IMG_HGHT;
	return (0);
}

static int	copy_vtcs_tab(t_fdf *fdf)
{
	if (!(fdf->vtcs_3d = (t_vertex*)malloc(sizeof(t_vertex) * fdf->nb_vertices)))
		return (print_sys_error(errno));
	ft_memcpy(fdf->vtcs_3d, fdf->vtcs_ref, sizeof(t_vertex) * fdf->nb_vertices);
	return (0);
}

static int	init_edges_tab(t_fdf *fdf)
{
	int	ind_edges;
	int	ind_vtx;

	fdf->nb_edges = (fdf->nb_cols - 1) * fdf->nb_rows\
			+ fdf->nb_cols * (fdf->nb_rows - 1);
	if (!(fdf->edges = (t_edge*)malloc(sizeof(t_edge) * fdf->nb_edges)))
		return (print_sys_error(errno));
	ind_vtx = -1;
	ind_edges = 0;
	while (++ind_vtx < fdf->nb_vertices)
	{
		if ((ind_vtx + 1) % fdf->nb_cols)
		{
			fdf->edges[ind_edges].vtx_1 = ind_vtx; 
			fdf->edges[ind_edges].vtx_2 = ind_vtx + 1; 
			ind_edges++;
		}
		if (ind_vtx + fdf->nb_cols < fdf->nb_vertices)
		{
			fdf->edges[ind_edges].vtx_1 = ind_vtx; 
			fdf->edges[ind_edges].vtx_2 = ind_vtx + fdf->nb_cols;
			ind_edges++;
		}
	}
	return (0);
}	

static void	compute_base_scale(t_fdf *fdf)
{
	int scale_x;
	int scale_y;

// voir s il ne faut pas en fait tester avec une premiere projection
	if (fdf->nb_cols == 1)
		scale_x = 0xFFFFFFFF;
	else
		scale_x = (IMG_WDTH - 2 * START_X_IMG) / (fdf->nb_cols - 1);
	if (fdf->nb_rows == 1)
		scale_y = 0xFFFFFFFF;
	else
		scale_y = (IMG_HGHT- 2 * START_Y_IMG) / (fdf->nb_rows- 1);
	fdf->base_scale = (scale_x > scale_y ? scale_x : scale_y);
}

int			init_fdf(t_fdf *fdf)
{
	if ((init_mlx(fdf)))
		return (1);
	if ((copy_vtcs_tab(fdf)))
		return (1);
	if ((init_edges_tab(fdf)))
		return (1);
	if (!(fdf->vtcs_2d = (t_vertex *)malloc(sizeof(t_vertex) * fdf->nb_vertices)))
		return ((print_sys_error(errno)));
//	init_matrices(fdf);
	compute_base_scale(fdf);
	fdf->mods.scale_coef = 1;
	fdf->mods.altitude_mod = 1;
	fdf->mods.proj = iso;
	return (0);
}