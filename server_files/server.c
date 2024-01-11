/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:48:57 by ddavlety          #+#    #+#             */
/*   Updated: 2024/01/11 20:29:17 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	free_exit(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (!s2)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
}

char	letter(char *bits)
{
	char	letter;

	letter = ft_atoi_binar(bits, ft_strlen(bits));
	// ft_putchar_fd(letter, 1);
	return (letter);
}

char	*msg(char *msg, char letter)
{
	char	*tmp;

	if (!msg)
		msg = ft_strdup("");
	free_exit(NULL, msg);
	tmp = msg;
	msg = ft_strjoin(msg, &letter);
	free(tmp);
	return (msg);
}

void	clean(char *s)
{
	ft_bzero(s, ft_strlen(s));
	free(s);
}

void	signal_user(int signum)
{
	static char	*message;
	static int	bit;
	static char	*bits;
	char		*tmp;

	if (!bits)
		bits = ft_strdup("");
	free_exit(NULL, bits);
	tmp = bits;
	if (signum == SIGUSR2 || signum == SIGUSR1)
		bit++;
	if (signum == SIGUSR2)
		bits = ft_strjoin(tmp, "1");
	if (signum == SIGUSR1)
		bits = ft_strjoin(tmp, "0");
	free_exit(tmp, bits);
	if (bit == 8)
	{
		message = msg(message, letter (bits));
		free
		ft_bzero(bits, 8);
		bit = 0;
	}
	if (message)
		ft_printf("%s\n", message);
}

// char swap_bits(char *bits)
// {
// 	char	*new_bits;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = sizeof(bits);
// 	new_bits = (char *)calloc(sizeof(bits), 1);
// 	if (!new_bits)
// 		error_exit(bits);
// 	new_bits[j--] = "\0"
// 	while(bits[i])
// 	{
// 		new_bits[j--] = bits[i--];
// 	}
// }

// char	*string()
// {

// }

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = &signal_user;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		;
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		;
	ft_printf("%i\n", getpid());


	while (1)
		usleep(1);
	return (0);
}
