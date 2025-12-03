/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:31:25 by zoeschne          #+#    #+#             */
/*   Updated: 2025/05/14 11:20:46 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	numlen(int nbr)
{
	int	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	print_num(int nbr)
{
	long int	nb;
	int			nlen;
	int			i;

	nb = nbr;
	nlen = numlen(nb);
	if (nb < 0)
	{
		write (1, "-", 1);
		nlen++;
		nb = -nb;
	}
	if (nb >= 0 && nb < 10)
	{
		i = nb + '0';
		write (1, &i, 1);
	}
	else
	{
		print_num(nb / 10);
		print_num(nb % 10);
	}
	return (nlen);
}
