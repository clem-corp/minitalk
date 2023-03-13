/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:22:43 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/13 22:22:14 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_srcs.h"

void send_signal(int pid, char *message);

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf( "Usage: ./client <server_pid> <message>\n");
		return(-1);
	}

	int server_pid = ft_atoi(argv[1]);
	char *message = argv[2];

	send_signal(server_pid, message);
	return 0;
}

void send_signal(int pid, char *message)
{
	unsigned char bits;
	unsigned long int i;
	unsigned long int j;

	bits = 0;
	i = 0;
	j = 0;
	while(message[i])
	{
		bits = (bits << 8) | message[i];
		j = 0;
		while(j < 8)
		{
			if ((bits & (1 << j)) != 0) //1
				kill(pid, SIGUSR1);
			else // 0
				kill(pid, SIGUSR2);
			usleep(800);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < 8)
	{
		kill(pid, SIGUSR1); // end
		usleep(800);
		j++;
	}
	return;
}
