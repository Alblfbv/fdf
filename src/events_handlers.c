/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:10:00 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/19 16:57:08 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		handle_key_events(int keycode, t_fdf *fdf)
{
	static t_event	tab[EVENTS_NB] = {{X_ROT_L, &handle_rot_events}, {X_ROT_R,\
		&handle_rot_events}, {Y_ROT_L, &handle_rot_events}, {Y_ROT_R,\
		&handle_rot_events}, {Z_ROT_L, &handle_rot_events}, {Z_ROT_R,\
		&handle_rot_events}, {X_TRANS_L, &handle_trans_events}, {X_TRANS_R,\
		&handle_trans_events}, {Y_TRANS_L, &handle_trans_events}, {Y_TRANS_R,\
		&handle_trans_events}, {Z_TRANS_L, &handle_trans_events}, {Z_TRANS_L,\
		&handle_trans_events}, {SCALE_M, &handle_scale_events}, {SCALE_P,\
		&handle_scale_events}, {ALT_M, &handle_altitutde_events}, {ALT_P,\
		&handle_altitude_events}, {ISO, &handle_projection_events}, {OTHER,\
		&handle_projection_events}, {ALIASING, &handle_draw_mode_event},\
		{RESET, &handle_reset_event}, {QUIT, &handle_quit_event}}; 
	int				i;

	i = -1;
	while (++i < EVENTS_NB)
		if (tab[i].keycode == keycode)
			return (tab[i].function(keycode, fdf));
	return (0);
}

int		handle_expose_event(t_fdf *fdf)
{
	free_fdf(fdf);
	exit (0);
	return (0);
}
