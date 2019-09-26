/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinit_matrices_proj.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:11:17 by allefebv          #+#    #+#             */
/*   Updated: 2019/09/26 19:14:10 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	proj_cavalier(t_fdf *fdf)
{
	fdf->mtx.proj_mtx[0][0] = 1;
	fdf->mtx.proj_mtx[0][1] = 0;
	fdf->mtx.proj_mtx[0][2] = atan(1) * (cos(-M_PI / 3));
	fdf->mtx.proj_mtx[0][3] = 0;
	fdf->mtx.proj_mtx[1][0] = 0;
	fdf->mtx.proj_mtx[1][1] = 1;
	fdf->mtx.proj_mtx[1][2] = atan(1) * (sin(-M_PI / 3));
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

static void	proj_cabinet(t_fdf *fdf)
{
	fdf->mtx.proj_mtx[0][0] = 1;
	fdf->mtx.proj_mtx[0][1] = 0;
	fdf->mtx.proj_mtx[0][2] = atan(2) * (cos(-M_PI / 3));
	fdf->mtx.proj_mtx[0][3] = 0;
	fdf->mtx.proj_mtx[1][0] = 0;
	fdf->mtx.proj_mtx[1][1] = 1;
	fdf->mtx.proj_mtx[1][2] = atan(2) * (sin(-M_PI / 3));
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

static void	proj_iso(t_fdf *fdf)
{
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

void		reinit_proj_matrix(t_fdf *fdf)
{
	static void(*fptr_tab[3])(t_fdf *) = {&proj_iso,\
		&proj_cavalier, &proj_cabinet};

	fptr_tab[fdf->mods.proj](fdf);
}
