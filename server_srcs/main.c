/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:22:33 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/14 17:37:45 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_srcs.h"

int	ft_strlen_spe(unsigned char *s)
{
	int	i;

	i = 0;
	while (s && *(s + i))
		i++;
	return (i);
}

unsigned char	*add_buff(unsigned char *buff, unsigned char count)
{
	int				len;
	unsigned char	*temp;
	int				i;

	i = -1;
	len = 0;
	if (ft_strlen_spe(buff) != 0)
		len = ft_strlen_spe(buff);
	temp = malloc((len + 2) * sizeof(char));
	if (!temp)
		return (ft_free(&buff));
	if (len == 0)
	{
		temp[0] = count;
		temp[1] = '\0';
	}
	else
	{
		while (buff[++i])
			temp[i] = buff[i];
		ft_free(&buff);
		temp[i] = count;
		temp[++i] = '\0';
	}
	return (temp);
}

void	action(int sig, siginfo_t *info, void *c __attribute__((unused)))
{
	static unsigned char	bits = 0;
	static int				count = 0;
	static unsigned char	*buff = NULL;
	pid_t					client_pid;

	client_pid = info->si_pid;
	if (client_pid && sig == SIGUSR1)
		count = count | 1 << bits;
	bits++;
	if (bits == 8 && count != 255)
	{
		buff = add_buff(buff, count);
		count = 0;
		bits = 0;
	}
	else if (bits == 8 && count == 255)
	{
		ft_printf("%s", buff);
		ft_printf("\n\nEnd of the transmission.\n\n");
		ft_free(&buff);
		bits = 0;
		count = 0;
		buff = NULL;
	}
}

int	main(void)
{
	struct sigaction	srv_action;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	srv_action.sa_mask = set;
	srv_action.sa_sigaction = action;
	srv_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &srv_action, 0);
	sigaction(SIGUSR2, &srv_action, 0);
	printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
