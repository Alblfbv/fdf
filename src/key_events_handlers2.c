/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_handlers2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:14:01 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/18 17:48:42 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			handle_altitude_events(int keycode, t_fdf *fdf);
{
	static int	tab[2] = {ALT_M, ALT_P};
	int			i;

	i = -1;
	while (++i < 2)
		if (tab[i] == keycode)
		{
			fdf->mods.altitude_mod += (!i ? -ALTITUDE_DELTA : ALTITUDE_DELTA)\
					* fdf->mods.altitude_mod;
			break ;
		}
	reinit_altitudes(fdf);
	display_object_routine(fdf);
	return (0);
}


int			handle_draw_mode_event(int keycode, t_fdf *fdf)
{
	(void)keycode;
	fdf->mods.draw_mode = (fdf->mods.draw_mode == iso ? other : iso);
	display_object_routine(fdf);
	return (0);
}

int			handle_reset_event(int keycode, t_fdf *fdf)
{
	(void)keycode;
	ft_bzero(&fdf->mods, sizeof(t_modifiers));
	fdf->mods.scale_coef = 1;
	fdf->mods.altitude_mod = 1;
	reinit_matrices(fdf);
	display_object_routine(fdf);
	return (0);
}

int			handle_quit(int keycode, t_fdf *fdf)
{
	(void)keycode;
	free_fdf(fdf);
	exit (0);
}
