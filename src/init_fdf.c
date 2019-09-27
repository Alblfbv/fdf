/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:37:17 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/27 14:58:49 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static void	compute_shifts(t_fdf *fdf)
{
	double	limit1;
	double	limit2;

	limit1 = -cos((double)(M_PI / 6)) * (fdf->nb_rows - 1) * fdf->base_scale;
	limit2 = cos((double)(M_PI / 6)) * (fdf->nb_cols - 1) * fdf->base_scale;
	fdf->shift_x = (int)(-limit1) + (IMG_WDTH - (int)(limit2 - limit1)) / 2;
	limit1 = 0;
	limit2 = sin((double)(M_PI / 6))\
		* (fdf->nb_cols + fdf->nb_rows - 2) * fdf->base_scale;
	fdf->shift_y = (IMG_HGHT - (int)(limit2 - limit1)) / 2;
}

static void	compute_base_scale(t_fdf *fdf)
{
	int		scale_x;
	int		scale_y;
	double	limit1;
	double	limit2;

	limit1 = -cos((double)(M_PI / 6)) * (fdf->nb_rows - 1);
	limit2 = cos((double)(M_PI / 6)) * (fdf->nb_cols - 1);
	scale_x = (IMG_WDTH - 2 * X_SHIFT) / ((int)(limit2 - limit1) == 0 ?\
		1 : (int)(limit2 - limit1));
	limit1 = 0;
	limit2 = sin((double)(M_PI / 6)) * (fdf->nb_cols + fdf->nb_rows - 2);
	scale_y = (IMG_HGHT - 2 * Y_SHIFT) / ((int)(limit2 - limit1) == 0 ?\
		1 : (int)(limit2 - limit1));
	fdf->base_scale = (scale_x > scale_y ? scale_y : scale_x);
}

int			init_fdf(t_fdf *fdf)
{
	if ((init_mlx(fdf)))
		return (1);
	if ((init_edges_tab(fdf)))
		return (1);
	if (!(fdf->vtcs_2d =\
		(t_vertex *)malloc(sizeof(t_vertex) * fdf->nb_vertices)))
		return ((print_sys_error(errno)));
	compute_base_scale(fdf);
	compute_shifts(fdf);
	ft_memset(&fdf->wireframe_col, 255, sizeof(t_subcolors));
	fdf->mods.scale_coef = 1;
	fdf->mods.alt_mod = 1;
	fdf->mods.col_updt = 1;
	init_tab_color(fdf);
	reinit_matrices(fdf);
	return (0);
}
