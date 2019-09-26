/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinit_matrices_rot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:24:44 by allefebv          #+#    #+#             */
/*   Updated: 2019/09/26 19:25:00 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reinit_rot_x_matrix(t_fdf *fdf)
{
	double		rot_x;

	rot_x = fdf->mods.rot_x * ROT_DELTA;
	fdf->mtx.rot_x_mtx[0][0] = 1;
	fdf->mtx.rot_x_mtx[0][1] = 0;
	fdf->mtx.rot_x_mtx[0][2] = 0;
	fdf->mtx.rot_x_mtx[0][3] = 0;
	fdf->mtx.rot_x_mtx[1][0] = 0;
	fdf->mtx.rot_x_mtx[1][1] = cos(rot_x);
	fdf->mtx.rot_x_mtx[1][2] = -sin(rot_x);
	fdf->mtx.rot_x_mtx[1][3] = 0;
	fdf->mtx.rot_x_mtx[2][0] = 0;
	fdf->mtx.rot_x_mtx[2][1] = sin(rot_x);
	fdf->mtx.rot_x_mtx[2][2] = cos(rot_x);
	fdf->mtx.rot_x_mtx[2][3] = 0;
	fdf->mtx.rot_x_mtx[3][0] = 0;
	fdf->mtx.rot_x_mtx[3][1] = 0;
	fdf->mtx.rot_x_mtx[3][2] = 0;
	fdf->mtx.rot_x_mtx[3][3] = 1;
}

void	reinit_rot_y_matrix(t_fdf *fdf)
{
	double		rot_y;

	rot_y = fdf->mods.rot_y * ROT_DELTA;
	fdf->mtx.rot_y_mtx[0][0] = cos(rot_y);
	fdf->mtx.rot_y_mtx[0][1] = 0;
	fdf->mtx.rot_y_mtx[0][2] = sin(rot_y);
	fdf->mtx.rot_y_mtx[0][3] = 0;
	fdf->mtx.rot_y_mtx[1][0] = 0;
	fdf->mtx.rot_y_mtx[1][1] = 1;
	fdf->mtx.rot_y_mtx[1][2] = 0;
	fdf->mtx.rot_y_mtx[1][3] = 0;
	fdf->mtx.rot_y_mtx[2][0] = -sin(rot_y);
	fdf->mtx.rot_y_mtx[2][1] = 0;
	fdf->mtx.rot_y_mtx[2][2] = cos(rot_y);
	fdf->mtx.rot_y_mtx[2][3] = 0;
	fdf->mtx.rot_y_mtx[3][0] = 0;
	fdf->mtx.rot_y_mtx[3][1] = 0;
	fdf->mtx.rot_y_mtx[3][2] = 0;
	fdf->mtx.rot_y_mtx[3][3] = 1;
}

void	reinit_rot_z_matrix(t_fdf *fdf)
{
	double		rot_z;

	rot_z = fdf->mods.rot_z * ROT_DELTA;
	fdf->mtx.rot_z_mtx[0][0] = cos(rot_z);
	fdf->mtx.rot_z_mtx[0][1] = -sin(rot_z);
	fdf->mtx.rot_z_mtx[0][2] = 0;
	fdf->mtx.rot_z_mtx[0][3] = 0;
	fdf->mtx.rot_z_mtx[1][0] = sin(rot_z);
	fdf->mtx.rot_z_mtx[1][1] = cos(rot_z);
	fdf->mtx.rot_z_mtx[1][2] = 0;
	fdf->mtx.rot_z_mtx[1][3] = 0;
	fdf->mtx.rot_z_mtx[2][0] = 0;
	fdf->mtx.rot_z_mtx[2][1] = 0;
	fdf->mtx.rot_z_mtx[2][2] = 1;
	fdf->mtx.rot_z_mtx[2][3] = 0;
	fdf->mtx.rot_z_mtx[3][0] = 0;
	fdf->mtx.rot_z_mtx[3][1] = 0;
	fdf->mtx.rot_z_mtx[3][2] = 0;
	fdf->mtx.rot_z_mtx[3][3] = 1;
}
