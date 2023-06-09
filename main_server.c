/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontign <amontign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:03:52 by amontign          #+#    #+#             */
/*   Updated: 2023/06/08 12:17:12 by amontign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

void sigHandler(int signal_num)
{
	static int	signalCount;
	static int	bin_tab[8];
	char display;

	if (signal_num == SIGUSR1)
	{
		bin_tab[signalCount] = 0;
	}
	else
	{
		bin_tab[signalCount] = 1;
	}
	signalCount++;
	if (signalCount == 8)
	{
		display = bin_to_dec(bin_tab);
		write(1, &display, 1);
		signalCount = 0;
	}
}

int main(void)
{
	struct sigaction action;
	action.sa_handler = sigHandler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;

	printf("PID : %d\n", getpid());
	if (sigaction(SIGUSR1, &action, NULL) < 0) {
		//error
		return (1);
	}
	if (sigaction(SIGUSR2, &action, NULL) < 0) {
		//error
		return (1);
	}
	while(1)
	{
		pause();
	}
	return (0);
}