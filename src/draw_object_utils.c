/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_object_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:00:06 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/26 16:25:35 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			give_interval(t_fdf *fdf, double z)
{
	int	i;

	i = -1;
	while (++i < NB_COLORS)
		if (z < fdf->color_tabs[fdf->mods.color_set][i].altitude)
			return (i);
	return (NB_COLORS);
}

void		swap_points(t_point_alt *p1, t_point_alt *p2)
{
	t_point_alt	swap;

	swap = *p1;
	*p1 = *p2;
	*p2 = swap;
}
