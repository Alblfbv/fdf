/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mlx_projections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:08:30 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/26 18:13:52 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

t_point	l_mlx_x_projection(t_point *var_point, double gradient, int value)
{
	t_point	proj_point;

	proj_point.x = value;
	proj_point.y = gradient * (proj_point.x - var_point->x) + var_point->y;
	return (proj_point);
}

t_point	l_mlx_y_projection(t_point *var_point, double gradient, int value)
{
	t_point	proj_point;

	proj_point.y = value;
	proj_point.x = (1 / gradient) * (proj_point.y - var_point->y)\
		+ var_point->x;
	return (proj_point);
}

t_point	l_mlx_projection(t_point *var_point, double gradient,\
	int axis, int value)
{
	t_point	proj_point;

	if (axis == X)
		proj_point = l_mlx_x_projection(var_point, gradient, value);
	else
		proj_point = l_mlx_y_projection(var_point, gradient, value);
	return (proj_point);
}
