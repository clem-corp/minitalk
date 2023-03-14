/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_srcs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:21:57 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/14 17:01:51 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_SRCS_H
# define SERVER_SRCS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "../libft/libft.h"
# include <signal.h>

void		print_pid(void);
void		*ft_free(unsigned char **s);

#endif
