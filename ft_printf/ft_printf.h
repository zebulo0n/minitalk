/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:45:47 by zoeschne          #+#    #+#             */
/*   Updated: 2025/05/14 11:56:53 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int	print_str(char *str);
int	print_ptr(void *ptr);
int	print_num(int nbr);
int	numlen(int nbr);
int	printp_base(unsigned long nbr);
int	printn_base(unsigned int nbr, char *base);
int	numlen_base(unsigned int nbr, char *base);
int	print_char(int c);
int	ft_strlen(char *str);
int	ft_printf(const char *str, ...);
int	def_format(char form, va_list arg_ptr);

#endif
