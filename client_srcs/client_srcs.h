/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_srcs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:38:20 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/14 16:56:03 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_SRCS_H
# define CLIENT_SRCS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "../libft/libft.h"
# include <signal.h>

void	end_signal(int pid);
void	send_signal(int pid, char *message);

#endif
