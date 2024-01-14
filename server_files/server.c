/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:48:57 by ddavlety          #+#    #+#             */
/*   Updated: 2024/01/14 15:07:03 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*add_char(char *str, char c)
{
	char	*ptr;

	ptr = (char *)malloc((ft_strlen(str) + 2) * sizeof(char));
	if (!ptr)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(ptr, str, ft_strlen(str) + 1);
	ft_strlcat(ptr, &c, ft_strlen(str) + 2);
	ptr[ft_strlen(str) + 1] = '\0';
	free(str);
	return (ptr);
}

void	clean(char **s)
{
	if (s)
	{
		free(*s);
		*s = NULL;
	}
}

void	add_letter(char **message, char *bits, int *bit)
{
	if (!*message)
		*message = ft_strdup("");
	if (!*message)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	*message = add_char(*message, ft_atoi_binar(bits, ft_strlen(bits)));
	if (!*message)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	ft_bzero(bits, 8);
	*bit = 0;
}

void	sigusr_handler(int signo, siginfo_t *info, void *context)
{
	static char	*message;
	static int	bit;
	static char	bits[9];

	(void)context;
	bits[8] = 0;
	if (signo == SIGUSR2)
		bits[bit++] = '1';
	if (signo == SIGUSR1)
		bits[bit++] = '0';
	if (bit == 8)
		add_letter(&message, bits, &bit);
	if (message && message[ft_strlen(message) - 1] == 4)
	{
		ft_printf("%s", message);
		clean(&message);
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sigusr_handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Error recieving SIGUSR1");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Error recieving SIGUSR2");
	ft_printf("%i\n", getpid());
	while (1)
		usleep(1);
	return (0);
}
