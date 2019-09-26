/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinit_matrices.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:16:34 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/26 19:25:26 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reinit_scale_matrix(t_fdf *fdf)
{
	t_modifiers	*mods;

	mods = &fdf->mods;
	fdf->mtx.scale_mtx[0][0] = mods->scale_coef * (double)fdf->base_scale;
	fdf->mtx.scale_mtx[0][1] = 0;
	fdf->mtx.scale_mtx[0][2] = 0;
	fdf->mtx.scale_mtx[0][3] = 0;
	fdf->mtx.scale_mtx[1][0] = 0;
	fdf->mtx.scale_mtx[1][1] = mods->scale_coef * (double)fdf->base_scale;
	fdf->mtx.scale_mtx[1][2] = 0;
	fdf->mtx.scale_mtx[1][3] = 0;
	fdf->mtx.scale_mtx[2][0] = 0;
	fdf->mtx.scale_mtx[2][1] = 0;
	fdf->mtx.scale_mtx[2][2] = mods->scale_coef * (double)fdf->base_scale;
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
	fdf->mtx.trans_mtx[0][3] = (double)mods->trans_x;
	fdf->mtx.trans_mtx[1][0] = 0;
	fdf->mtx.trans_mtx[1][1] = 1;
	fdf->mtx.trans_mtx[1][2] = 0;
	fdf->mtx.trans_mtx[1][3] = (double)mods->trans_y;
	fdf->mtx.trans_mtx[2][0] = 0;
	fdf->mtx.trans_mtx[2][1] = 0;
	fdf->mtx.trans_mtx[2][2] = 1;
	fdf->mtx.trans_mtx[2][3] = (double)mods->trans_z;
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
	fdf->mtx.move_mtx[0][3] = (double)(mods->move_x + fdf->shift_x);
	fdf->mtx.move_mtx[1][0] = 0;
	fdf->mtx.move_mtx[1][1] = 1;
	fdf->mtx.move_mtx[1][2] = 0;
	fdf->mtx.move_mtx[1][3] = (double)(mods->move_y + fdf->shift_y);
	fdf->mtx.move_mtx[2][0] = 0;
	fdf->mtx.move_mtx[2][1] = 0;
	fdf->mtx.move_mtx[2][2] = 1;
	fdf->mtx.move_mtx[2][3] = 0;
	fdf->mtx.move_mtx[3][0] = 0;
	fdf->mtx.move_mtx[3][1] = 0;
	fdf->mtx.move_mtx[3][2] = 0;
	fdf->mtx.move_mtx[3][3] = 1;
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
