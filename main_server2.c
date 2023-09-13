/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontign <amontign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:31:30 by amontign          #+#    #+#             */
/*   Updated: 2023/07/25 10:48:39 by amontign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	main(void)
{
	struct sigaction	action;
	struct sigaction	action_int;
	char				*pid;

	action.sa_sigaction = sig_handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	action_int.sa_handler = sig_int_handler;
	sigemptyset(&action_int.sa_mask);
	action_int.sa_flags = 0;
	pid = ft_itoa(getpid());
	ft_putstr("PID : ");
	ft_putstr(pid);
	free(pid);
	ft_putstr("\n");
	if (sigaction(SIGUSR1, &action, NULL) < 0)
		return (1);
	if (sigaction(SIGUSR2, &action, NULL) < 0)
		return (1);
	if (sigaction(SIGINT, &action_int, NULL) < 0)
		return (1);
	while (1)
		pause();
	return (0);
}

char	*ft_realloc(char *g_bin_tab, int signal_count)
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
	if (signal_count > 0 && g_bin_tab)
	{
		free(g_bin_tab);
		g_bin_tab = NULL;
	}
	return (tmp_tab);
}

void	sig_handler_norme(int *signal_count, int *client)
{
	*signal_count = 0;
	*client = 0;
}
