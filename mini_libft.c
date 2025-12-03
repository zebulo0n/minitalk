/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:37:26 by zoeschne          #+#    #+#             */
/*   Updated: 2025/08/29 11:37:43 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	nb;
	int	sign;

	nb = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb *= 10;
		nb = nb + (*nptr - 48);
		nptr++;
	}
	return (nb * sign);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	setup_client(int ac, char *av, pid_t *server_pid)
{
	if (ac != 3)
	{
		write(1, "Usage : ./client server_PID string_to_send\n", 44);
		return (0);
	}
	*server_pid = (pid_t)ft_atoi(av);
	if (*server_pid <= 0)
	{
		write(1, "ERROR : Invalid PID\n", 21);
		return (0);
	}
	if (kill(*server_pid, 0) == -1)
	{
		write(1, "ERROR : Server PID does not exist\n", 35);
		return (0);
	}
	return (1);
}
