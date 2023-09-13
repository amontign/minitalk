/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontign <amontign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:34:28 by amontign          #+#    #+#             */
/*   Updated: 2023/07/25 10:57:46 by amontign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

void	ft_putstr(char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
void	sig_int_handler(int sig);
void	sig_handler(int signal_num, siginfo_t *info, void *ptr);
char	**ft_split(char const *s);
int		is_nb(char *str);
int		ft_atoi(const char *nptr);
char	*ft_realloc(char *g_bin_tab, int signal_count);
void	sig_handler_norme(int *signal_count, int *client);
void	handle_sig(int sig);
void	handle_sig2(int sig);
void	msg_to_bin_complete(int (*tab_int_msg)[8], char *msg);

#endif