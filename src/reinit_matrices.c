/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinit_matrices.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:16:34 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/19 17:06:05 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reinit_rot_matrix(t_fdf *fdf)
{
	// a remplir en fonction de fdf->mods.rot_x, fdf->mods.rot_y, fdf->mods.rot_z
}

void	reinit_scale_matrix(t_fdf *fdf)
{
	// a remplir en fonction de fdf->mods.scale_coef
}

void	reinit_trans_matrix(t_fdf *fdf)
{
	// a remplir en fonction de fdf->mods.trans_x, fdf->mods.trans_y, fdf->mods.trans_z
}

void	reinit_proj_matrix(t_fdf *fdf)
{
	// a remplir en fonction de fdf->mods.proj
}

void	reinit_matrices(t_fdf *fdf);
{
	reinit_rot_matric(fdf);
	reinit_scale_matrix(fdf);
	reinit_trans_matric(fdf);
	reinit_proj_matrix(fdf);
}
