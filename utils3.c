/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontign <amontign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:08:01 by amontign          #+#    #+#             */
/*   Updated: 2023/07/25 09:31:05 by amontign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_count_words(char const *s, int *lw_size)
{
	int	lg;
	int	nb_words;

	lg = ft_strlen(s);
	*lw_size = (lg % 100);
	nb_words = (lg / 100) + (*lw_size > 0);
	return (nb_words);
}

int	alloc_tabs(char **res, int lw_size, int nb_words)
{
	int	i;

	i = 0;
	while (i < nb_words - 1)
	{
		res[i] = malloc(sizeof(char) * 101);
		if (!res[i])
			return (0);
		i++;
	}
	if (lw_size > 0)
		res[i] = malloc(sizeof(char) * (lw_size + 1));
	else
		res[i] = malloc(sizeof(char) * 101);
	if (!res[i])
		return (0);
	return (1);
}

void	complete_tab(int nb_words, int lw_size, char **res, const char *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < nb_words)
	{
		if (lw_size > 0 && i == (nb_words - 1))
		{
			j = -1;
			while (++j < lw_size)
				res[i][j] = s[i * 100 + j];
			res[i][j] = '\0';
		}
		else
		{
			j = -1;
			while (++j < 100)
				res[i][j] = s[i * 100 + j];
			res[i][j] = '\0';
		}
		i++;
	}
	res[i] = NULL;
}

char	**ft_split(char const *s)
{
	char	**res;
	int		nb_words;
	int		lw_size;

	nb_words = ft_count_words(s, &lw_size);
	res = malloc((nb_words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	if (!alloc_tabs(res, lw_size, nb_words))
		return (NULL);
	complete_tab(nb_words, lw_size, res, s);
	return (res);
}

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
