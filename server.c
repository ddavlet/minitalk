/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:48:57 by ddavlety          #+#    #+#             */
/*   Updated: 2024/01/05 20:35:16 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	signal_int(int signum)
{
	ft_printf("test..");
}

int	main(void)
{
	signal(SIGINT, signal_int);

	while (1)
	{
		sleep(1);
	}
	return (0);
}
