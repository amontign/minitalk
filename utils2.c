/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:30:08 by amontign          #+#    #+#             */
/*   Updated: 2023/07/06 11:30:09 by amontign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_nbr_length(int n)
{
	int	l;

	l = (n <= 0);
	while (n)
	{
		n /= 10;
		l++;
	}
	return (l);
}

char	*ft_itoa_complete(int l, char *res, int n, int n2)
{
	int	i;

	i = 1;
	while (i <= l - (n2 < 0))
	{
		res[l - i] = n % 10 + 48;
		n /= 10;
		i++;
	}
	res[l] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	int		l;
	int		n2;
	char	*res;

	n2 = 0;
	l = ft_nbr_length(n);
	res = malloc((l + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (n == -2147483648)
	{
		ft_strlcpy(res, "-2147483648", 12);
		return (res);
	}
	if (n < 0)
	{
		res[0] = '-';
		n2 = n;
		n = -n;
	}
	res = ft_itoa_complete(l, res, n, n2);
	return (res);
}

int	is_nb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
