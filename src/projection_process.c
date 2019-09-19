/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:29:37 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/19 17:06:04 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	transform_coor(t_fdf *fdf)
{
	int		index;

	index = -1;
	while (++index < fdf->vertices)
	{
		fdf->vtcs_2d[i].x = // formule pour calculer a partir de vcts_3d et tmp_mtx 
		fdf->vtcs_2d[i].y = // formule pour calculer a partir de vcts_3d et tmp_mtx 
	}
}	

void	compute_matrices(t_fdf *fdf)
{
	fdf->vtcs_2d[i].z = fdf->vtcs_3d[i].z * fdf->mods.altitude_mod; /* le z sera important
	au moment de calculer la projection, il ne faut pas utiliser celui de la matrice 3d
	car on veut pouvoir reset*/
	// algo pour calculer tmp matrices a partir des 4 autres matrices
}
