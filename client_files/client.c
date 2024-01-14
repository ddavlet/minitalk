/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:47:09 by ddavlety          #+#    #+#             */
/*   Updated: 2024/01/14 15:03:03 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	s_letter(char ltr, int pid)
{
	unsigned int	len;

	len = 8;
	while (len--)
	{
		if ((ltr >> len) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

void	encode(char *message, int pid)
{
	while (*message)
		s_letter(*message++, pid);
	s_letter(4, pid);
}

void	signal_user(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Signal recieved back!\n");
	exit (0);
}

void	wait(void)
{
	static int	i;

	if (i > 0)
	{
		ft_printf("Answer from server is not recieved!\n");
		exit (1);
	}
	sleep(20);
	i++;
}

int	main(int argc, char *argv[])
{
	int					pid;
	char				*message;
	struct sigaction	sa;

	sa.sa_handler = &signal_user;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Error recieving SIGUSR1");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Error recieving SIGUSR2");
	if (argc != 3)
	{
		ft_printf("Usage: %s <server_PID> <message>\n", argv[0]);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	encode(message, pid);
	while (1)
		wait();
	return (0);
}
