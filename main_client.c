/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontign <amontign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:11:35 by amontign          #+#    #+#             */
/*   Updated: 2023/07/28 08:01:58 by amontign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	g_message_receive;

int	(*msg_to_bin_alloc(char *msg))[8]
{
	int	nb_of_char;
	int	(*tab_int_msg)[8];

	nb_of_char = 0;
	while (msg[nb_of_char])
	{
		nb_of_char++;
	}
	tab_int_msg = (int (*)[8])malloc(sizeof(*tab_int_msg) * (nb_of_char + 1));
	if (!tab_int_msg)
	{
		exit(1);
	}
	return (tab_int_msg);
}

void	main2(int i, int (*tab_int_msg)[8], char **argv)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		while (g_message_receive)
		{
		}
		if (tab_int_msg[i][j] == 0)
			kill(ft_atoi(argv[1]), SIGUSR1);
		else
			kill(ft_atoi(argv[1]), SIGUSR2);
		g_message_receive = 1;
		j++;
	}
}

void	handle_sig(int sig)
{
	(void)sig;
	g_message_receive = 0;
}

void	sig_gestion(void)
{
	g_message_receive = 0;
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig2);
}

int	main(int argc, char **argv)
{
	int		(*tab_int_msg)[8];
	int		i;
	int		nb_of_char;

	if (argc != 3 || is_nb(argv[1]) == 0)
		return (1);
	sig_gestion();
	tab_int_msg = msg_to_bin_alloc(argv[2]);
	msg_to_bin_complete(tab_int_msg, argv[2]);
	nb_of_char = 0;
	while (argv[2][nb_of_char])
		nb_of_char++;
	i = -1;
	while (++i < nb_of_char)
		main2(i, tab_int_msg, argv);
	i = -1;
	while (++i < 8)
	{
		while (g_message_receive)
			i = (i * 2) / 2;
		kill(ft_atoi(argv[1]), SIGUSR1);
		g_message_receive = 1;
	}
	free(tab_int_msg);
	return (0);
}
