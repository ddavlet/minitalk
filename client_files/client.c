/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:47:09 by ddavlety          #+#    #+#             */
/*   Updated: 2024/01/11 20:14:37 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	s_letter(char ltr, int pid)
{
	unsigned int	len;

	len = 8;
	while (len--)
	{
		usleep(2000000);
		if ((ltr >> len) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
	}
}

void	encode(char *message, int pid)
{
	while (*message)
		s_letter(*message++, pid);
}

// void	send(int bit, int pid)
// {

// }

int	main(int argc, char *argv[])
{
	int		pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_PID> <message>\n", argv[0]);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	encode(message, pid);

	return (0);
}
//https://gitlab.com/42-elopez-r/minitalk
