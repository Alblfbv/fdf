/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:29:37 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/26 19:20:02 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			transform_coor(t_fdf *fdf)
{
	int			index;
	t_vertex	tmp_point;

	index = -1;
	while (++index < fdf->nb_vertices)
	{
		tmp_point = fdf->vtcs_3d[index];
		fdf->vtcs_2d[index].x = fdf->mtx.tmp_mtx[0][0] * tmp_point.x
			+ fdf->mtx.tmp_mtx[0][1] * tmp_point.y\
			+ fdf->mtx.tmp_mtx[0][2] * tmp_point.z\
			+ fdf->mtx.tmp_mtx[0][3] * 1;
		fdf->vtcs_2d[index].y = fdf->mtx.tmp_mtx[1][0] * tmp_point.x
			+ fdf->mtx.tmp_mtx[1][1] * tmp_point.y\
			+ fdf->mtx.tmp_mtx[1][2] * tmp_point.z\
			+ fdf->mtx.tmp_mtx[1][3] * 1;
		fdf->vtcs_2d[index].z = fdf->vtcs_3d[index].z * fdf->mods.alt_mod;
	}
}

static void		copy_mtx(double dst_mtx[4][4], double src_mtx[4][4])
{
	int	i;

	i = -1;
	while (++i < 4)
		ft_memcpy(dst_mtx[i], src_mtx[i], sizeof(double) * 4);
}

static void		multiply_matrices(double tmp_mtx[4][4], double factor_mtx[4][4])
{
	double	product_mtx[4][4];
	int		i;
	int		j;

	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
			product_mtx[i][j] = tmp_mtx[0][j] * factor_mtx[i][0]\
				+ tmp_mtx[1][j] * factor_mtx[i][1]
				+ tmp_mtx[2][j] * factor_mtx[i][2]
				+ tmp_mtx[3][j] * factor_mtx[i][3];
	}
	copy_mtx(tmp_mtx, product_mtx);
}

void			compute_tmp_matrix(t_fdf *fdf)
{
	copy_mtx(fdf->mtx.tmp_mtx, fdf->mtx.alt_mtx);
	multiply_matrices(fdf->mtx.tmp_mtx, fdf->mtx.scale_mtx);
	multiply_matrices(fdf->mtx.tmp_mtx, fdf->mtx.trans_mtx);
	multiply_matrices(fdf->mtx.tmp_mtx, fdf->mtx.rot_x_mtx);
	multiply_matrices(fdf->mtx.tmp_mtx, fdf->mtx.rot_y_mtx);
	multiply_matrices(fdf->mtx.tmp_mtx, fdf->mtx.rot_z_mtx);
	multiply_matrices(fdf->mtx.tmp_mtx, fdf->mtx.proj_mtx);
	multiply_matrices(fdf->mtx.tmp_mtx, fdf->mtx.move_mtx);
}
