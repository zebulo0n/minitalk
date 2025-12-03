/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printn_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:21:31 by zoeschne          #+#    #+#             */
/*   Updated: 2025/05/14 11:24:50 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	numlen_base(unsigned int nbr, char *base)
{
	int	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr)
	{
		nbr /= ft_strlen(base);
		len++;
	}
	return (len);
}

int	printn_base(unsigned int nbr, char *base)
{
	unsigned int		blen;
	int					nlen;

	blen = ft_strlen(base);
	nlen = numlen_base(nbr, base);
	if (nbr < 0)
	{
		write (1, "-", 1);
		nlen++;
		nbr = -nbr;
	}
	if (nbr < blen)
		write (1, &base[nbr], 1);
	else
	{
		printn_base(nbr / blen, base);
		printn_base(nbr % blen, base);
	}
	return (nlen);
}	
