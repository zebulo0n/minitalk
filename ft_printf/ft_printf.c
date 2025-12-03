/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:53:41 by zoeschne          #+#    #+#             */
/*   Updated: 2025/05/14 11:19:27 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		nbytes;

	if (!str)
		return (-1);
	va_start (args, str);
	i = 0;
	nbytes = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			nbytes += def_format(str[i + 1], args);
			i++;
		}
		else
			nbytes += write (1, (str + i), 1);
		i++;
	}
	return (nbytes);
}

// int main()
// {
// 	int total1, total2;
// 	printf("orign\t");
// 	total1 = printf("%p", NULL);
// 	printf("\nft\t");
// 	total2 = ft_printf("%p", NULL);
// 	printf("\n%d\t%d", total1, total2);
// }
/*
int main()
{
	int total, total2;
	total = printf("void ptr %p \n", "2147483647");
	total2 = ft_printf("void ptr %p \n", "2147483647");
	printf("orign %d \t ft %d\n", total, total2);

	total = printf("void ptr %p \n", "-2147483648");
        total2 = ft_printf("void ptr %p \n", "-2147483648");
        printf("orign %d \t ft %d\n", total, total2);

	total = printf("void ptr %p \n", "-4294967295UL");
        total2 = ft_printf("void ptr %p \n", "-4294967295UL");
        printf("orign %d \t ft %d\n", total, total2);

	total = printf("void ptr %p \n", "0");
        total2 = ft_printf("void ptr %p \n", "0");
        printf("orign %d \t ft %d\n", total, total2);

	total = printf("string %s \n", "hello world");
        total2 = ft_printf("string %s \n", "hello world");
        printf("orign %d \t ft %d\n", total, total2);

	total = printf("decimal %d \n", -1);
        total2 = ft_printf("decimal %d \n", -1);
        printf("orign %d \t ft %d\n", total, total2);

	total = printf("integer %i \n", -1);
        total2 = ft_printf("integer %i \n", -1);
        printf("orign %d \t ft %d\n", total, total2);

	total = printf("unsigned dec %u \n", -1);
        total2 = ft_printf("unsigned dec %u \n", -1);
        printf("orign %d \t ft %d\n", total, total2);

	total = printf("hexa %x \n", 123456789);
        total2 = ft_printf("hexa %x \n", 123456789);
        printf("orign %d \t ft %d\n", total, total2);

	total = printf("HEXA %X \n", -123456789);
        total2 = ft_printf("HEXA %X \n", -123456789);
        printf("orign %d \t ft %d\n", total, total2);

	total = printf("%%\n");
        total2 = ft_printf("%%\n");
        printf("orign %d \t ft %d\n", total, total2);

}
*/
