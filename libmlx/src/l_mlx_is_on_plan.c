/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mlx_is_on_plan.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:16:52 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/26 18:08:04 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

int	l_mlx_is_x_on_plan(double x, t_plan *plan)
{
	if (x < (double)plan->x_min || x > (double)plan->x_max)
		return (0);
	return (1);
}

int	l_mlx_is_y_on_plan(double y, t_plan *plan)
{
	if (y < (double)plan->y_min || y > (double)plan->y_max)
		return (0);
	return (1);
}

int	l_mlx_is_on_plan(t_point *point, t_plan *plan)
{
	if (!l_mlx_is_x_on_plan(point->x, plan)
		|| !l_mlx_is_y_on_plan(point->y, plan))
		return (0);
	return (1);
}
