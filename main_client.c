/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontign <amontign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:11:35 by amontign          #+#    #+#             */
/*   Updated: 2023/06/22 09:05:42 by amontign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi(const char *nptr)
{
	int	neg;
	int	i;
	int	res;

	neg = 1;
	i = 0;
	res = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		res = res * 10 + nptr[i] - 48;
		i++;
	}
	return (res * neg);
}

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

void	msg_to_bin_complete(int (*tab_int_msg)[8], char *msg)
{
	int	i;
	int	j;
	int	char_tmp;

	i = 0;
	while (msg[i])
	{
		char_tmp = (int)msg[i];
		j = 7;
		while (j >= 0)
		{
			tab_int_msg[i][j] = char_tmp & 1;
			char_tmp = char_tmp >> 1;
			j--;
		}
		i++;
	}
	j = 0;
	while (j < 8)
	{
		tab_int_msg[i][j] = 0;
		j++;
	}
}

void	main2(int i, int (*tab_int_msg)[8], char **argv)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if (tab_int_msg[i][j] == 0)
			kill(ft_atoi(argv[1]), SIGUSR1);
		else
			kill(ft_atoi(argv[1]), SIGUSR2);
		usleep(100);
		j++;
	}
}

int	main(int argc, char **argv)
{
	int	(*tab_int_msg)[8];
	int	i;
	int	nb_of_char;

	if (argc != 3)
		return (1);
	tab_int_msg = msg_to_bin_alloc(argv[2]);
	msg_to_bin_complete(tab_int_msg, argv[2]);
	i = 0;
	nb_of_char = 0;
	while (argv[2][nb_of_char])
		nb_of_char++;
	while (i < nb_of_char)
	{
		main2(i, tab_int_msg, argv);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		kill(ft_atoi(argv[1]), SIGUSR1);
		usleep(100);
		i++;
	}
	return (0);
}
