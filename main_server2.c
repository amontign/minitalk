/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:31:30 by amontign          #+#    #+#             */
/*   Updated: 2023/07/06 11:31:32 by amontign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	main(void)
{
	struct sigaction	action;
	struct sigaction	action_int;
	char				*pid;

	action.sa_handler = sig_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
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
