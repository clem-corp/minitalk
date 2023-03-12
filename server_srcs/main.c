/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:22:33 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/12 20:25:22 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_srcs.h"

int main()
{
    signal(SIGINT, signal_handler);

    printf("Waiting for signal...\n");
    pause();
    printf("Resuming execution.\n");
	return (0);
}