/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qkherzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:42:10 by qkherzi           #+#    #+#             */
/*   Updated: 2021/11/29 17:21:15 by qkherzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

int		send(char *line, int pid_serveur);
int		send_bin(int pid_serveur, char str);
int		valid_pid(char *pid_serveur);
void	define_user(int sig);
void	define(int sig, siginfo_t *use, void *cont);
char	*ft_itoa(int n);
int		ft_isdigit(int c);
char	*ft_strjoin(char const *s1, char s2);
void	ft_putstr_fd(char *s, int fd);
int		ft_strisdigit(char *str);
int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);

#endif
