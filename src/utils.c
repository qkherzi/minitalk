/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qkherzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:17:53 by qkherzi           #+#    #+#             */
/*   Updated: 2021/11/29 17:23:01 by qkherzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Minitalk.h"

char	*ft_itoa(int n)
{
	char	buff[12];
	int		i;
	int		val;

	i = 11;
	buff[i--] = 0;
	if (!n)
		buff[i--] = '0';
	val = n;
	if (n < 0)
		n = -n;
	if (n < 0)
		return (ft_strdup("-2147483648"));
	while (n)
	{
		buff[i--] = n % 10 + '0';
		n /= 10;
	}
	if (val < 0)
		buff[i--] = '-';
	return (ft_strdup(buff + i + 1));
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strjoin(char const *s1, char s2)
{
	char	*strings;
	int		i;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = ft_strlen(s1) + 2;
	strings = ft_calloc(sizeof(char), i);
	i = 0;
	if (strings == 0)
		return (0);
	while (s1[i] != 0)
	{
		strings[i] = s1[i];
		i++;
	}
	strings[i] = s2;
	return (strings);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_strisdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && !(str[i] == '-'
				&& ft_isdigit(str[i + 1])))
			return (0);
		i++;
	}
	return (1);
}
