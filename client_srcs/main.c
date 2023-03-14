/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:22:43 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/14 23:16:38 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_srcs.h"

void	end_signal(int pid)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		kill(pid, SIGUSR1);
		usleep(800);
		j++;
	}
	return ;
}

// SIGUSR1 == 1
// SIGUSR2 == 0
void	send_signal(int pid, char *message)
{
	unsigned char		bits;
	unsigned long int	i;
	unsigned long int	j;

	bits = 0;
	i = 0;
	j = 0;
	while (message[i])
	{
		bits = (bits << 8) | message[i];
		j = 0;
		while (j < 8)
		{
			if ((bits & (1 << j)) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(800);
			j++;
		}
		i++;
	}
	end_signal(pid);
	return ;
}

void	signal_handler(int sig)
{
	ft_printf("Received signal");
	exit(sig);
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*message;

	server_pid = 0;
	message = NULL;
	if (argc != 3)
	{
		ft_printf("Usage: ./client <server_pid> <message>\n");
		return (-1);
	}
	signal(SIGUSR1, signal_handler);
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	send_signal(server_pid, message);
	pause();
	return (0);
}
