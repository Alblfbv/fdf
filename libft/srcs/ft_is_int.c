/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:56:59 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/16 16:07:23 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_int(char *str)
{
	int		i;
	int		neg;
	long	nb;

	i = 0;
	neg = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	i--;
	nb = 0;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		nb = nb * 10 + str[i] - '0';
		if (nb > (neg ? 2147483648 : 2147483647))
			return (0);
	}
	return (1);
}
