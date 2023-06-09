/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontign <amontign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:03:52 by amontign          #+#    #+#             */
/*   Updated: 2023/06/09 10:50:22 by amontign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	bin_to_dec(char *bin_tab, int iter)
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
			res += (bin_tab[i] - 48) * puissance;
			puissance *= 2;
			i--;
		}
		write(1, &res, 1);
		j++;
	}
	free(bin_tab);
}

void	check_end(char *bin_tab, int signal_count)
{
	int	i;

	i = signal_count - 8;
	while (i < signal_count)
	{
		if (bin_tab[i] == 49)
			return ;
		i++;
	}
	bin_to_dec(bin_tab, (signal_count / 8));
}

char	*ft_realloc(char *bin_tab, int signal_count)
{
	char	*tmp_tab;
	int		i;

	tmp_tab = malloc(sizeof(char) * (signal_count + 2));
	if (!tmp_tab)
	{
		free(bin_tab);
		exit(1);
	}
	i = 0;
	while (i < signal_count)
	{
		tmp_tab[i] = bin_tab[i];
		i++;
	}
	free(bin_tab);
	return (tmp_tab);
}

void	sig_handler(int signal_num)
{
	static int	signal_count;
	static char	*bin_tab;

	if (!bin_tab)
		bin_tab = malloc(sizeof(char));
	if (!bin_tab)
	{
		exit(1);
	}
	else
		bin_tab = ft_realloc(bin_tab, signal_count);
	if (signal_num == SIGUSR1)
	{
		bin_tab[signal_count] = 48;
	}
	else
	{
		bin_tab[signal_count] = 49;
	}
	signal_count++;
	bin_tab[signal_count] = 0;
	if (signal_count % 8 == 0)
		check_end(bin_tab, signal_count);
}

int	main(void)
{
	struct sigaction	action;

	action.sa_handler = sig_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	//printf("PID : %d\n", getpid());
	if (sigaction(SIGUSR1, &action, NULL) < 0)
	{
		return (1);
	}
	if (sigaction(SIGUSR2, &action, NULL) < 0)
	{
		return (1);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
