/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_handlers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:10:12 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/26 17:13:16 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		handle_rot_events(int keycode, t_fdf *fdf)
{
	static int	tab[6] = {X_ROT_L, X_ROT_R, Y_ROT_L, Y_ROT_R,\
		Z_ROT_L, Z_ROT_R};
	static void	(*ptr_tab[3])(t_fdf *) = {&reinit_rot_x_matrix,\
		&reinit_rot_y_matrix, &reinit_rot_z_matrix};
	int			i;

	i = -1;
	while (++i < 6)
		if (tab[i] == keycode)
		{
			if (i < 2)
				fdf->mods.rot_x += (!(i % 2) ? -1 : 1) % 36;
			else if (i < 4)
				fdf->mods.rot_y += (!(i % 2) ? -1 : 1) % 36;
			else
				fdf->mods.rot_z += (!(i % 2) ? -1 : 1) % 36;
			break ;
		}
	ptr_tab[i / 2](fdf);
	display_object_routine(fdf);
	return (0);
}

int		handle_scale_events(int keycode, t_fdf *fdf)
{
	static int	tab[2] = {SCALE_M, SCALE_P};
	int			i;

	i = -1;
	while (++i < 2)
		if (tab[i] == keycode)
		{
			fdf->mods.scale_coef += (!i ? -SCALE_DELTA : SCALE_DELTA)\
					* fdf->mods.scale_coef;
			break ;
		}
	reinit_scale_matrix(fdf);
	display_object_routine(fdf);
	return (0);
}

int		handle_trans_events(int keycode, t_fdf *fdf)
{
	static int	tab[6] = {X_TRANS_L, X_TRANS_R, Y_TRANS_L, Y_TRANS_R,\
		Z_TRANS_L, Z_TRANS_R};
	int			i;

	i = -1;
	while (++i < 6)
		if (tab[i] == keycode)
		{
			if (i < 2)
				fdf->mods.trans_x += (!(i % 2) ?\
						-TRANS_DELTA : TRANS_DELTA);
			else if (i < 4)
				fdf->mods.trans_y += (!(i % 2) ?\
						-TRANS_DELTA : TRANS_DELTA);
			else
				fdf->mods.trans_z += (!(i % 2) ?\
						-TRANS_DELTA : TRANS_DELTA);
			break ;
		}
	reinit_trans_matrix(fdf);
	display_object_routine(fdf);
	return (0);
}

int		handle_proj_events(int keycode, t_fdf *fdf)
{
	static int	tab[3] = {ISO, CAVALIER, CABINET};
	int			i;

	i = -1;
	while (++i < 3)
		if (tab[i] == keycode)
		{
			fdf->mods.proj = i;
			break ;
		}
	reinit_proj_matrix(fdf);
	display_object_routine(fdf);
	return (0);
}
