/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mlx_actualize_points.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:04:07 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/26 18:07:47 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

int		l_mlx_actualize_points(t_point *start, t_point *end, t_plan *plan)
{
	if ((l_mlx_is_on_plan(start, plan)) && (l_mlx_is_on_plan(end, plan)))
		return (1);
	if (!l_mlx_is_on_plan(start, plan) && !check_projection(start, end, plan))
		return (0);
	if (!l_mlx_is_on_plan(end, plan) && !check_projection(end, start, plan))
		return (0);
	return (1);
}
