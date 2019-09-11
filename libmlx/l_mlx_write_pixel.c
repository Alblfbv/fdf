/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mlx_write_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:30:24 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/11 15:34:56 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** only works for bpp = 32
** endianess already taken care of
*/

#include "libmlx.h"

void	l_mlx_write_pixel(t_img *img, int x, int y, int color)
{
	int	buf_pos;

	buf_pos = y * img->size_line + x;
	ft_memcpy(img->buf + buf_pos, color, sizeof(int));
}
