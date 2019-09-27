/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 10:37:02 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/27 16:01:09 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		print_usage(void)
{
	ft_putstr_fd("usage: ./fdf [map]\n", 2);
	return (1);
}

int		print_sys_error(int errnum)
{
	ft_putstr_fd("fdf: error: ", 2);
	ft_putstr_fd(strerror(errnum), 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

int		print_input_error(int errnum)
{
	ft_putstr_fd("fdf: error: ", 2);
	if (errnum == 1)
		ft_putstr_fd("Not an int value\n", 2);
	if (errnum == 2)
		ft_putstr_fd("Wrong number of columns\n", 2);
	if (errnum == 3)
		ft_putstr_fd("Empty file\n", 2);
	return (1);
}

int		print_mlx_error(int errnum)
{
	ft_putstr_fd("fdf: error: ", 2);
	if (errnum == 1)
		ft_putstr_fd("Couldn't initialize MinilibX\n", 2);
	if (errnum == 2)
		ft_putstr_fd("Couldn't create a new window\n", 2);
	if (errnum == 1)
		ft_putstr_fd("Couldn't create a new image\n", 2);
	return (1);
}
