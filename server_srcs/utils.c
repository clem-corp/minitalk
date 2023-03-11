/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:31:27 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/11 01:39:02 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_srcs.h"

static void	ft_print_int(pid_t pid)
{
	if (pid > 9)
		ft_print_int(pid / 10);
	pid = pid % 10 + '0';
	write(1, &pid, 1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && *(s + i))
		i++;
	return (i);
}

void	print_pid(void)
{
	char	*pid_msg;
	int		srv_pid;

	srv_pid = getpid();
	pid_msg = "pid server : ";
	write(1, pid_msg, ft_strlen(pid_msg));
	ft_print_int(srv_pid);
	write(1, "\n", 1);
}

void	*ft_free(unsigned char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
	return (NULL);
}
