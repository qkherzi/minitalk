/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qkherzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:18:11 by qkherzi           #+#    #+#             */
/*   Updated: 2021/11/29 17:18:15 by qkherzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	str = malloc(size * count);
	if (!str)
		return (NULL);
	i = 0;
	while (i != size * count)
	{
		str[i] = 0;
		i++;
	}	
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	str = ft_calloc(sizeof(char), i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	neg = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if ((str[i + 1] == '-') || (str[i + 1] == '+'))
			return (0);
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * neg);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
