/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinit_matrices.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:16:34 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/24 12:59:33 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reinit_rot_x_matrix(t_fdf *fdf)
{
	double		rot_x;

	rot_x = fdf->mods.rot_x * (M_PI / 180);
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

	rot_y = fdf->mods.rot_y * (M_PI / 180);
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

	rot_z = fdf->mods.rot_z * (M_PI / 180);
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

void	reinit_scale_matrix(t_fdf *fdf)
{
	t_modifiers	*mods;

	mods = &fdf->mods;
	fdf->mtx.scale_mtx[0][0] = mods->scale_coef * fdf->base_scale;
	fdf->mtx.scale_mtx[0][1] = 0;
	fdf->mtx.scale_mtx[0][2] = 0;
	fdf->mtx.scale_mtx[0][3] = 0;
	fdf->mtx.scale_mtx[1][0] = 0;
	fdf->mtx.scale_mtx[1][1] = mods->scale_coef * fdf->base_scale;
	fdf->mtx.scale_mtx[1][2] = 0;
	fdf->mtx.scale_mtx[1][3] = 0;
	fdf->mtx.scale_mtx[2][0] = 0;
	fdf->mtx.scale_mtx[2][1] = 0;
	fdf->mtx.scale_mtx[2][2] = mods->scale_coef * fdf->base_scale;
	fdf->mtx.scale_mtx[2][3] = 0;
	fdf->mtx.scale_mtx[3][0] = 0;
	fdf->mtx.scale_mtx[3][1] = 0;
	fdf->mtx.scale_mtx[3][2] = 0;
	fdf->mtx.scale_mtx[3][3] = 1;
}

void	reinit_alt_matrix(t_fdf *fdf)
{
	double		alt_mod;

	alt_mod = fdf->mods.alt_mod;
	fdf->mtx.alt_mtx[0][0] = 1;
	fdf->mtx.alt_mtx[0][1] = 0;
	fdf->mtx.alt_mtx[0][2] = 0;
	fdf->mtx.alt_mtx[0][3] = 0;
	fdf->mtx.alt_mtx[1][0] = 0;
	fdf->mtx.alt_mtx[1][1] = 1;
	fdf->mtx.alt_mtx[1][2] = 0;
	fdf->mtx.alt_mtx[1][3] = 0;
	fdf->mtx.alt_mtx[2][0] = 0;
	fdf->mtx.alt_mtx[2][1] = 0;
	fdf->mtx.alt_mtx[2][2] = alt_mod;
	fdf->mtx.alt_mtx[2][3] = 0;
	fdf->mtx.alt_mtx[3][0] = 0;
	fdf->mtx.alt_mtx[3][1] = 0;
	fdf->mtx.alt_mtx[3][2] = 0;
	fdf->mtx.alt_mtx[3][3] = 1;
}

void	reinit_trans_matrix(t_fdf *fdf)
{
	t_modifiers	*mods;

	mods = &fdf->mods;
	fdf->mtx.trans_mtx[0][0] = 1;
	fdf->mtx.trans_mtx[0][1] = 0;
	fdf->mtx.trans_mtx[0][2] = 0;
	fdf->mtx.trans_mtx[0][3] = mods->trans_x;
	fdf->mtx.trans_mtx[1][0] = 0;
	fdf->mtx.trans_mtx[1][1] = 1;
	fdf->mtx.trans_mtx[1][2] = 0;
	fdf->mtx.trans_mtx[1][3] = mods->trans_y;
	fdf->mtx.trans_mtx[2][0] = 0;
	fdf->mtx.trans_mtx[2][1] = 0;
	fdf->mtx.trans_mtx[2][2] = 1;
	fdf->mtx.trans_mtx[2][3] = mods->trans_z;
	fdf->mtx.trans_mtx[3][0] = 0;
	fdf->mtx.trans_mtx[3][1] = 0;
	fdf->mtx.trans_mtx[3][2] = 0;
	fdf->mtx.trans_mtx[3][3] = 1;
}

void	reinit_move_matrix(t_fdf *fdf)
{
	t_modifiers	*mods;

	mods = &fdf->mods;
	fdf->mtx.move_mtx[0][0] = 1;
	fdf->mtx.move_mtx[0][1] = 0;
	fdf->mtx.move_mtx[0][2] = 0;
	fdf->mtx.move_mtx[0][3] = mods->move_x;
	fdf->mtx.move_mtx[1][0] = 0;
	fdf->mtx.move_mtx[1][1] = 1;
	fdf->mtx.move_mtx[1][2] = 0;
	fdf->mtx.move_mtx[1][3] = mods->move_y;
	fdf->mtx.move_mtx[2][0] = 0;
	fdf->mtx.move_mtx[2][1] = 0;
	fdf->mtx.move_mtx[2][2] = 1;
	fdf->mtx.move_mtx[2][3] = 0;
	fdf->mtx.move_mtx[3][0] = 0;
	fdf->mtx.move_mtx[3][1] = 0;
	fdf->mtx.move_mtx[3][2] = 0;
	fdf->mtx.move_mtx[3][3] = 1;
}

void	reinit_proj_matrix(t_fdf *fdf)
{
	t_projection	*proj;

	proj = &fdf->mods.proj;
	fdf->mtx.proj_mtx[0][0] = cos(M_PI / 6);
	fdf->mtx.proj_mtx[0][1] = -cos(M_PI / 6);
	fdf->mtx.proj_mtx[0][2] = 0;
	fdf->mtx.proj_mtx[0][3] = 0;
	fdf->mtx.proj_mtx[1][0] = sin(M_PI / 6);
	fdf->mtx.proj_mtx[1][1] = sin(M_PI / 6);
	fdf->mtx.proj_mtx[1][2] = -1;
	fdf->mtx.proj_mtx[1][3] = 0;
	fdf->mtx.proj_mtx[2][0] = 0;
	fdf->mtx.proj_mtx[2][1] = 0;
	fdf->mtx.proj_mtx[2][2] = 0;
	fdf->mtx.proj_mtx[2][3] = 0;
	fdf->mtx.proj_mtx[3][0] = 0;
	fdf->mtx.proj_mtx[3][1] = 0;
	fdf->mtx.proj_mtx[3][2] = 0;
	fdf->mtx.proj_mtx[3][3] = 1;
}

void	reinit_matrices(t_fdf *fdf)
{
	reinit_alt_matrix(fdf);
	reinit_scale_matrix(fdf);
	reinit_trans_matrix(fdf);
	reinit_rot_x_matrix(fdf);
	reinit_rot_y_matrix(fdf);
	reinit_rot_z_matrix(fdf);
	reinit_proj_matrix(fdf);
	reinit_move_matrix(fdf);
}
