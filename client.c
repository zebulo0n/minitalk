/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:16:56 by zoeschne          #+#    #+#             */
/*   Updated: 2025/08/29 11:41:49 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile int	g_received = 0;

int	send_char(char c, pid_t pid)
{
	int	i;
	int	prblm;

	i = 7;
	while (i >= 0)
	{
		g_received = 0;
		if ((c >> i) & 1)
			prblm = kill(pid, SIGUSR2);
		else
			prblm = kill(pid, SIGUSR1);
		if (prblm == -1)
		{
			ft_printf("ERROR : Couldnt send %dth bit of %c character\n", i, c);
			return (0);
		}
		while (!g_received)
			usleep(50);
		i--;
	}
	return (1);
}

void	handler(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sig == SIGUSR2)
		g_received = 2;
	else
		g_received = 1;
}

int	send_len(int len, pid_t pid)
{
	int	i;
	int	prblm;

	i = 31;
	g_received = 0;
	while (i >= 0)
	{
		if ((len >> i) & 1)
			prblm = kill(pid, SIGUSR2);
		else
			prblm = kill(pid, SIGUSR1);
		if (prblm == -1)
		{
			write(1, "ERROR : Couldnt send first packet.\n", 36);
			return (0);
		}
		usleep(300);
		i--;
	}
	while (g_received != 2)
		usleep(50);
	g_received = 1;
	return (1);
}

int	send_mess(char *mess, pid_t server_pid)
{
	int	i;
	int	len;

	len = ft_strlen(mess);
	if (len > 2147483647)
	{
		write (1, "Message too long\n", 18);
		return (0);
	}
	if (!send_len(len, server_pid))
		return (0);
	if (g_received == 1)
	{
		i = 0;
		while (mess[i])
		{
			if (!send_char(mess[i], server_pid))
				return (0);
			usleep(100);
			i++;
		}
		write(1, "Message sent successfully!\n", 28);
		return (1);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	pid_t				server_pid;
	struct sigaction	sa;

	if (!av[2] || !av[2][0])
	{
		write (1, "Write a message.\n", 18);
		return (0);
	}
	if (!setup_client(ac, av[1], &server_pid))
		return (0);
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR2, &sa, NULL) == -1
		|| sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		write(1, "Client : Signal handler setup failed\n", 37);
		return (0);
	}
	if (!send_mess(av[2], server_pid))
	{
		write(1, "ERROR : Couldnt send message.\n", 31);
	}
}
