/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:01:52 by zoeschne          #+#    #+#             */
/*   Updated: 2025/05/14 11:56:28 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printp_base(unsigned long nbr)
{
	int		nlen;
	char	*base;

	nlen = 0;
	base = "0123456789abcdef";
	if (nbr >= 16)
		nlen += printp_base(nbr / 16);
	nlen += print_char(base[nbr % 16]);
	return (nlen);
}

int	print_ptr(void *ptr)
{
	unsigned long	address;

	address = (unsigned long)ptr;
	if (address == 0)
		return (print_str("(nil)"));
	print_str("0x");
	return (printp_base(address) + 2);
}
