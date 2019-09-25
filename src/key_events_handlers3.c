/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_handlers3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:34:43 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/25 20:21:29 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			handle_rgb_events(int keycode, t_fdf *fdf)
{
	if (fdf->mods.color_mode != unicolor)
		return (0);
	fdf->mods.col_updt = 1;
	if (keycode == RED_M && fdf->wireframe_col.red > 100 + COL_DELTA)
		fdf->wireframe_col.red -= COL_DELTA;
	if (keycode == RED_P && fdf->wireframe_col.red < 255 - COL_DELTA)
		fdf->wireframe_col.red += COL_DELTA;
	if (keycode == GREEN_M && fdf->wireframe_col.green > 100 + COL_DELTA)
		fdf->wireframe_col.green -= COL_DELTA;
	if (keycode == GREEN_P && fdf->wireframe_col.green < 255 - COL_DELTA)
		fdf->wireframe_col.green += COL_DELTA;
	if (keycode == BLUE_M && fdf->wireframe_col.blue > 100 + COL_DELTA)
		fdf->wireframe_col.blue -= COL_DELTA;
	if (keycode == BLUE_P && fdf->wireframe_col.blue < 255 - COL_DELTA)
		fdf->wireframe_col.blue += COL_DELTA;
	display_object_routine(fdf);
	return (0);
}
