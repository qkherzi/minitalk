/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qkherzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:42:58 by qkherzi           #+#    #+#             */
/*   Updated: 2021/11/29 17:39:27 by qkherzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Minitalk.h"

static int	g_wait = 0;

int	valid_pid(char *pid_serveur)
{
	int	i;

	i = 0;
	while (pid_serveur[i])
	{
		if (ft_isdigit(pid_serveur[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	send_bin(int pid_serveur, char str)
{
	int	size;

	size = 0;
	while (size < 8)
	{
		g_wait = 0;
		usleep(50);
		if ((str >> size) & 1)
		{
			if (kill(pid_serveur, SIGUSR1) == -1)
				return (1);
		}
		else if (kill(pid_serveur, SIGUSR2) == -1)
			return (1);
		while (g_wait == 0)
		{
		}
		size++;
	}
	return (0);
}

int	send(char *line, int pid_serveur)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strjoin(line, '\n');
	while (str[i] != 0)
	{
		if (send_bin(pid_serveur, str[i]))
			return (1);
		i++;
	}
	free(str);
	return (0);
}

void	waiting(int i)
{
	(void)i;
	g_wait = 1;
	return ;
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		ft_putstr_fd("Error: arguments\n", 1);
		exit(EXIT_FAILURE);
	}
	if (!(ft_strisdigit(av[1])))
	{
		ft_putstr_fd("Invalid PID\n", 1);
		exit(EXIT_FAILURE);
	}
	if (ac == 3 && ft_atoi(av[1]) != 0)
	{
		signal(SIGUSR2, waiting);
		if (send(av[2], ft_atoi(av[1])))
			ft_putstr_fd("Error: Invalid PID\n", 1);
	}
	else if (ac < 3 || ac > 3)
	{
		ft_putstr_fd("Error: argument\n", 1);
		exit(EXIT_FAILURE);
	}
	return (0);
}
