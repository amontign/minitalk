/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontign <amontign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:49:34 by amontign          #+#    #+#             */
/*   Updated: 2023/07/25 10:52:55 by amontign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	handle_sig2(int sig)
{
	(void)sig;
	exit(1);
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
