/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:54:13 by zoeschne          #+#    #+#             */
/*   Updated: 2025/05/14 10:53:12 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	def_format(char form, va_list arg_ptr)
{
	int	count;

	count = 0;
	if (form == 'c')
		count += print_char(va_arg(arg_ptr, int));
	else if (form == 's')
		count += print_str(va_arg(arg_ptr, char *));
	else if (form == 'p')
		count += print_ptr(va_arg(arg_ptr, void *));
	else if (form == 'd' || form == 'i')
		count += print_num(va_arg(arg_ptr, int));
	else if (form == 'u')
		count += printn_base(va_arg(arg_ptr, unsigned int), "0123456789");
	else if (form == 'x')
		count += printn_base(va_arg(arg_ptr, int), "0123456789abcdef");
	else if (form == 'X')
		count += printn_base(va_arg(arg_ptr, int), "0123456789ABCDEF");
	else if (form == '%')
		count += write (1, "%", 1);
	else
	{
		count += write (1, "%", 1);
		count += write (1, &form, 1);
	}
	return (count);
}
