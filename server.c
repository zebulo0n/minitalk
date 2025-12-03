/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:23:19 by zoeschne          #+#    #+#             */
/*   Updated: 2025/08/29 13:05:37 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_len_received = 0;

void	handle_len(int sig, char **string, siginfo_t *info, int *len)
{
	static int	bit_index = 31;

	if (sig == -1)
	{
		bit_index = 31;
		return ;
	}
	if (sig == SIGUSR2)
		*len |= (1 << bit_index);
	bit_index--;
	if (bit_index < 0)
	{
		*string = malloc(sizeof(char) * (*len + 1));
		(*string)[*len] = '\0';
		if (!*string)
			return ;
		bit_index = 31;
		kill(info->si_pid, SIGUSR2);
		g_len_received = 1;
	}
}

void	display_string(char **string, int *i, int *len)
{
	ft_putstr_fd(*string, 1);
	write(1, "\n", 1);
	free(*string);
	*string = NULL;
	*i = 0;
	*len = 0;
	g_len_received = 0;
}

void	handle_mess(int sig, char **string, siginfo_t *info, int *len)
{
	static unsigned char	c = 0;
	static int				bit_index = 7;
	static int				i = 0;

	if (sig == -1)
	{
		c = 0;
		bit_index = 7;
		i = 0;
		return ;
	}
	if (sig == SIGUSR2)
		c |= (1 << bit_index);
	bit_index--;
	kill(info->si_pid, SIGUSR1);
	if (bit_index < 0)
	{
		(*string)[i++] = c;
		bit_index = 7;
		c = 0;
		if (i == *len)
		{
			display_string(string, &i, len);
		}
	}
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static int		len = 0;
	static char		*string = NULL;
	static pid_t	old_pid = 0;

	(void)context;
	if (old_pid != 0 && old_pid != info->si_pid)
	{
		free(string);
		string = NULL;
		len = 0;
		g_len_received = 0;
		handle_len(-1, NULL, NULL, NULL);
		handle_mess(-1, NULL, NULL, NULL);
	}
	old_pid = info->si_pid;
	if (g_len_received == 0)
		handle_len(sig, &string, info, &len);
	else
		handle_mess(sig, &string, info, &len);
}

int	main(int ac, char *av[])
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		write(1, "Usage : ./server\n", 18);
		return (0);
	}
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	ft_printf("Server PID : %d\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(1, "Server : Signal handler setup failed\n", 38);
		return (0);
	}
	while (1)
		pause();
}
