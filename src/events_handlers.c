/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:10:00 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/27 16:11:18 by rkirszba         ###   ########.fr       */
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
		&handle_trans_events}, {Z_TRANS_L, &handle_trans_events}, {Z_TRANS_R,\
		&handle_trans_events}, {SCALE_M, &handle_scale_events}, {SCALE_P,\
		&handle_scale_events}, {ALT_M, &handle_alt_events}, {ALT_P,\
		&handle_alt_events}, {ISO, &handle_proj_events}, {CAVALIER,\
		&handle_proj_events}, {CABINET, &handle_proj_events},\
		{ALIASING, &handle_draw_mode_event}, {RESET, &handle_reset_event},\
		{QUIT, &handle_quit_event}, {MOVE_U, &handle_move_events},\
		{MOVE_D, &handle_move_events}, {MOVE_L, &handle_move_events},\
		{MOVE_R, &handle_move_events}, {RED_M, &handle_rgb_events},\
		{RED_P, &handle_rgb_events}, {GREEN_M, &handle_rgb_events},\
		{GREEN_P, &handle_rgb_events}, {BLUE_M, &handle_rgb_events},\
		{BLUE_P, &handle_rgb_events}, {UNICOLOR, &handle_colmod_events},\
		{POLYCOLOR, &handle_colmod_events}, {COLOR_SET, &handle_colset_event}};
	int				i;

	i = -1;
	while (++i < EVENTS_NB)
		if (tab[i].keycode == keycode)
			return (tab[i].function(keycode, fdf));
	return (0);
}

int		handle_quit_event_mouse(t_fdf *fdf)
{
	free_fdf(fdf);
	exit(0);
	return (0);
}
