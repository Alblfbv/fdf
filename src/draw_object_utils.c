/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_object_utils.cc                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:00:06 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/17 15:08:10 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color_alt	*tab_color_alt(void)
{
	static t_color_alt	tab[NB_COLORS] = {{DEEP_BLUE_INT, DEEP_BLUE_ALT},\
		{LIGHT_BLUE_INT, LIGHT_BLUE_ALT}, {GREEN_INT, GREEN_ALT},\
		{BROWN_INT, BROWN_ALT}, {WHITE_INT, WHITE_ALT}};
	
	return (tab);
}

int			give_interval(double z1)
{
	if (z1 < DEEP_BLUE_ALT)
		return (0);
	if (z1 >= DEEP_BLUE_ALT && z1 < LIGHT_BLUE_ALT)
		return (1);
	if (z1 >= LIGHT_BLUE_ALT && z1 < GREEN_ALT)
		return (2);
	if (z1 >= GREEN_ALT && z1 < BROWN_ALT)
		return (3);
	if (z1 >= BROWN_ALT && z1 < WHITE_ALT)
		return (4);
	return (5);
}

void		swap_points(t_point_alt *p1, t_point_alt *p2)
{
	t_point_alt	swap;

	swap = *p1;
	*p1 = *p2;
	*p2 = swap;
}
