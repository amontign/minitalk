/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontign <amontign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:03:52 by amontign          #+#    #+#             */
/*   Updated: 2023/07/25 10:49:01 by amontign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*g_bin_tab;

void	bin_to_dec(char *g_bin_tab, int iter)
{
	int	res;
	int	puissance;
	int	i;
	int	j;

	j = 0;
	while (j < iter)
	{
		res = 0;
		puissance = 1;
		i = 7 + (j * 8);
		while (i >= (j * 8))
		{
			res += (g_bin_tab[i] - 48) * puissance;
			puissance *= 2;
			i--;
		}
		write(1, &res, 1);
		j++;
	}
}

int	check_end(char *g_bin_tab, int signal_count)
{
	int	i;

	i = signal_count - 8;
	while (i < signal_count)
	{
		if (g_bin_tab[i] == 49)
			return (0);
		i++;
	}
	bin_to_dec(g_bin_tab, (signal_count / 8));
	return (1);
}

void	complete_bin_tab(int signal_num, int signal_count)
{
	if (signal_num == SIGUSR1)
		g_bin_tab[signal_count] = 48;
	else
		g_bin_tab[signal_count] = 49;
}

void	sig_handler(int signal_num, siginfo_t *info, void *ptr)
{
	static int	signal_count;
	static int	client;

	if (client != 0 && client != (int)info->si_pid)
		return (kill((int)info->si_pid, SIGUSR2), (void)ptr);
	if ((int)info->si_pid == getpid())
		return ;
	client = (int)info->si_pid;
	g_bin_tab = ft_realloc(g_bin_tab, signal_count);
	if (!g_bin_tab)
		exit(1);
	complete_bin_tab(signal_num, signal_count);
	g_bin_tab[++signal_count] = 0;
	if (signal_count % 8 == 0)
	{
		if (check_end(g_bin_tab, signal_count))
		{
			if (g_bin_tab)
				free(g_bin_tab);
			g_bin_tab = NULL;
			sig_handler_norme(&signal_count, &client);
		}
	}
	usleep(20);
	kill(client, SIGUSR1);
}

void	sig_int_handler(int sig)
{
	(void)sig;
	if (g_bin_tab)
	{
		free(g_bin_tab);
		g_bin_tab = NULL;
	}
	exit(0);
}
