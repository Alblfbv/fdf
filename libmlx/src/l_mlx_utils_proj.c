/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mlx_utils_proj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:12:33 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/26 18:37:08 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

static int	check_proj_y(t_point *var_point, t_point *ref_point, t_plan *plan,\
		double gradient)
{
	t_point	proj_p;

	if (var_point->y < plan->y_min)
	{
		proj_p = l_mlx_projection(var_point, gradient, Y, plan->y_min);
		if (l_mlx_is_x_on_plan(proj_p.x, plan) && ref_point->y >= plan->y_min)
		{
			proj_p.color = l_mlx_compute_color(var_point, ref_point, &proj_p);
			proj_p.endian = var_point->endian;
			*var_point = proj_p;
			return (1);
		}
	}
	else if (var_point->y > plan->y_max)
	{
		proj_p = l_mlx_projection(var_point, gradient, Y, plan->y_max);
		if (l_mlx_is_x_on_plan(proj_p.x, plan) && ref_point->y <= plan->y_max)
		{
			proj_p.color = l_mlx_compute_color(var_point, ref_point, &proj_p);
			proj_p.endian = var_point->endian;
			*var_point = proj_p;
			return (1);
		}
	}
	return (0);
}

static int	check_proj_x(t_point *var_point, t_point *ref_point, t_plan *plan,\
		double gradient)
{
	t_point	proj_p;

	if (var_point->x < plan->x_min)
	{
		proj_p = l_mlx_projection(var_point, gradient, X, plan->x_min);
		if (l_mlx_is_y_on_plan(proj_p.y, plan) && ref_point->x >= plan->x_min)
		{
			proj_p.color = l_mlx_compute_color(var_point, ref_point, &proj_p);
			proj_p.endian = var_point->endian;
			*var_point = proj_p;
			return (1);
		}
	}
	else if (var_point->x > plan->x_max)
	{
		proj_p = l_mlx_projection(var_point, gradient, X, plan->x_max);
		if (l_mlx_is_y_on_plan(proj_p.y, plan) && ref_point->x <= plan->x_max)
		{
			proj_p.color = l_mlx_compute_color(var_point, ref_point, &proj_p);
			proj_p.endian = var_point->endian;
			*var_point = proj_p;
			return (1);
		}
	}
	return (0);
}

static int	check_proj_horizontal(t_point *var_point,\
	t_point *ref_point, t_plan *plan)
{
	t_point	proj_p;

	if (!l_mlx_is_y_on_plan(var_point->y, plan))
		return (0);
	if (l_mlx_is_x_on_plan(var_point->x, plan))
		return (1);
	if (var_point->x < plan->x_min)
	{
		if (ref_point->x < plan->x_min)
			return (0);
		proj_p.y = var_point->y;
		proj_p.x = plan->x_min;
		proj_p.color = l_mlx_compute_color(var_point, ref_point, &proj_p);
		proj_p.endian = var_point->endian;
		*var_point = proj_p;
		return (1);
	}
	if (ref_point->x > plan->x_max)
		return (0);
	proj_p.y = var_point->y;
	proj_p.x = plan->x_max;
	proj_p.color = l_mlx_compute_color(var_point, ref_point, &proj_p);
	proj_p.endian = var_point->endian;
	*var_point = proj_p;
	return (1);
}

static int	check_proj_vertical(t_point *var_point,\
	t_point *ref_point, t_plan *plan)
{
	t_point	proj_p;

	if (!l_mlx_is_x_on_plan(var_point->x, plan))
		return (0);
	if (l_mlx_is_y_on_plan(var_point->y, plan))
		return (1);
	if (var_point->y < plan->y_min)
	{
		if (ref_point->y < plan->y_min)
			return (0);
		proj_p.x = var_point->x;
		proj_p.y = plan->y_min;
		proj_p.color = l_mlx_compute_color(var_point, ref_point, &proj_p);
		proj_p.endian = var_point->endian;
		*var_point = proj_p;
		return (1);
	}
	if (ref_point->y > plan->y_max)
		return (0);
	proj_p.x = var_point->x;
	proj_p.y = plan->y_max;
	proj_p.color = l_mlx_compute_color(var_point, ref_point, &proj_p);
	proj_p.endian = var_point->endian;
	*var_point = proj_p;
	return (1);
}

int			check_projection(t_point *var_point,\
	t_point *ref_point, t_plan *plan)
{
	double	gradient;

	if (var_point->x == ref_point->x)
		return (check_proj_vertical(var_point, ref_point, plan));
	if (var_point->y == ref_point->y)
		return (check_proj_horizontal(var_point, ref_point, plan));
	gradient = l_mlx_compute_gradient(var_point, ref_point);
	if (!l_mlx_is_x_on_plan(var_point->x, plan)
		&& check_proj_x(var_point, ref_point, plan, gradient))
		return (1);
	return (check_proj_y(var_point, ref_point, plan, gradient));
}
