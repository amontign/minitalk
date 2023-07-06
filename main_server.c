/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontign <amontign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:03:52 by amontign          #+#    #+#             */
/*   Updated: 2023/06/23 15:14:12 by amontign         ###   ########.fr       */
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

char	*ft_realloc(char *g_bin_tab, int signal_count, int first_time)
{
	char	*tmp_tab;
	int		i;

	tmp_tab = malloc(sizeof(char) * (signal_count + 2));
	if (!tmp_tab)
	{
		free(g_bin_tab);
		exit(1);
	}
	i = 0;
	while (i < signal_count)
	{
		tmp_tab[i] = g_bin_tab[i];
		i++;
	}
	if (signal_count > 0 || first_time == 0)
		free(g_bin_tab);
	return (tmp_tab);
}

void	sig_handler(int signal_num)
{
	static int	signal_count;
	static int	first_time;

	g_bin_tab = ft_realloc(g_bin_tab, signal_count, first_time);
	if (signal_count != 0)
	{
		first_time = 1;
	}
	if (!g_bin_tab)
		exit(1);
	if (signal_num == SIGUSR1)
		g_bin_tab[signal_count] = 48;
	else
		g_bin_tab[signal_count] = 49;
	g_bin_tab[++signal_count] = 0;
	if (signal_count % 8 == 0)
	{
		if (check_end(g_bin_tab, signal_count))
		{
			signal_count = 0;
			free(g_bin_tab);
			g_bin_tab = NULL;
		}
	}
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
