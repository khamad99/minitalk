/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:47:31 by kalshaer          #+#    #+#             */
/*   Updated: 2023/01/24 11:18:33 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* to initiate variables in handler_sigusr_server function */

static void	initiate(int *i, pid_t *cpid, unsigned char *c, siginfo_t *info)
{
	*i = 0;
	*cpid = info->si_pid;
	*c = 0;
}

/* handled funtion that control the signals received from clinet and 
store it in char c thn print it on STDOUT  */

static void	handler_sigusr_server(int sig, siginfo_t *info, void *ucontext)
{
	static int				i;
	static pid_t			cpid;
	static unsigned char	c;

	(void)ucontext;
	if ((!i && !cpid) || !i)
		initiate(&i, &cpid, &c, info);
	c = c | (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			cpid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID is: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler_sigusr_server;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
