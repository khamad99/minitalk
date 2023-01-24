/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:21:16 by kalshaer          #+#    #+#             */
/*   Updated: 2023/01/24 11:09:35 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* this function handle the SIGUSR1 and SIGUSR2 
that have been sent from server.*/

static void	handler_sigusr(int sig)
{
	static int	i;
	if (!i)
		i = 0;
	if (sig == SIGUSR1)
		i++;
	else
	{
		ft_printf("received: %d\n", i);
		exit(0);
	}
}

/* this function take a string enterd by the client 
and send it to the server as a bit comparison.
it sends SIGUSR1 if the compered bit is 0 and SIGUSR2 if it is 1.*/

static void	sendstr(int pid, char *str, char *c)
{
	int	i;

	while (*str)
	{
		i = 8;
		*c = *str++;
		while (i--)
		{
			if ((*c >> i) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}	
		usleep(100);
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep (100);
	}
	usleep(100);
}

int	main(int argc, char **argv)
{
	char	c;

	if (argc != 3 || ft_strlen(argv[2]) == 0)
		return (1);
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	ft_printf("Sent: %d\n", ft_strlen(argv[2]));
	sendstr(ft_atoi(argv[1]), argv[2], &c);
	while (1)
		pause();
	return (0);
}
