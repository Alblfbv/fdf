/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_handlers2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:14:01 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/27 16:11:32 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			handle_alt_events(int keycode, t_fdf *fdf)
{
	static int	tab[2] = {ALT_M, ALT_P};
	int			i;

	i = -1;
	while (++i < 2)
		if (tab[i] == keycode)
		{
			fdf->mods.alt_mod += (!i ? -ALTITUDE_DELTA : ALTITUDE_DELTA)\
					* fdf->mods.alt_mod;
			break ;
		}
	reinit_alt_matrix(fdf);
	display_object_routine(fdf);
	return (0);
}

int			handle_draw_mode_event(int keycode, t_fdf *fdf)
{
	(void)keycode;
	fdf->mods.draw_mode =\
		(fdf->mods.draw_mode == xiaolin ? bresenham : xiaolin);
	display_object_routine(fdf);
	return (0);
}

int			handle_reset_event(int keycode, t_fdf *fdf)
{
	(void)keycode;
	ft_bzero(&fdf->mods, sizeof(t_modifiers));
	fdf->mods.scale_coef = 1;
	fdf->mods.alt_mod = 1;
	fdf->mods.col_updt = 1;
	ft_memset(&fdf->wireframe_col, 255, sizeof(t_subcolors));
	reinit_matrices(fdf);
	display_object_routine(fdf);
	return (0);
}

int			handle_quit_event(int keycode, t_fdf *fdf)
{
	(void)keycode;
	free_fdf(fdf);
	exit(0);
}

int			handle_move_events(int keycode, t_fdf *fdf)
{
	static int	tab[4] = {MOVE_L, MOVE_R, MOVE_U, MOVE_D};
	int			i;

	i = -1;
	while (++i < 4)
		if (tab[i] == keycode)
		{
			if (i < 2)
				fdf->mods.move_x += (!(i % 2) ?\
						MOVE_DELTA : -MOVE_DELTA);
			else
				fdf->mods.move_y += (!(i % 2) ?\
						MOVE_DELTA : -MOVE_DELTA);
			break ;
		}
	reinit_move_matrix(fdf);
	display_object_routine(fdf);
	return (0);
}
