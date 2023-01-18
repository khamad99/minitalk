/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:47:31 by kalshaer          #+#    #+#             */
/*   Updated: 2023/01/17 14:24:14 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler_sigusr_server(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	static int				i = 0;
	static pid_t			cpid = 0;
	static unsigned char	c = 0;

	if (!cpid)
		cpid = info->si_pid;
	c = c | (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(cpid, SIGUSR2);
			cpid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(cpid, SIGUSR1);
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction sa;
	
	ft_printf("Server ID is: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler_sigusr_server;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}