/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontign <amontign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:03:52 by amontign          #+#    #+#             */
/*   Updated: 2023/05/31 19:17:54 by amontign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_data
{
	int bin_tab[8];
	int signalCount;
}				t_data;

t_data *data;

int bin_to_dec(int bin_tab[8]) {
	int res = 0;
	int puissance = 1;
	int	i;

	i = 7;
	while (i >= 0)
	{
		res += bin_tab[i] * puissance;
		puissance *= 2;
		i--;
	}
	return (res);
}

void sigHandler(int sig)
{
	printf("uwu");
	usleep(10);
	if (sig == 10)
	{
		data->bin_tab[data->signalCount] = 0;
	}
	else
	{
		data->bin_tab[data->signalCount] = 1;
	}
	data->signalCount++;
	if (data->signalCount == 8)
	{
		printf("%c", (char)bin_to_dec(data->bin_tab));
		data->signalCount = 0;
	}
}

int main(void)
{
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->signalCount = 0;
	printf("PID : %d\n", getpid());
	signal(SIGUSR1, sigHandler);
	signal(SIGUSR2, sigHandler);
	while(1)
	{
		pause();
	}
	free(data);
	return (0);
}