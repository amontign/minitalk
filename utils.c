#include "utils.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	lg;	

	lg = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (lg);
}

void	ft_putstr(char *s)
{
	int	i;
	i = 0;

	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

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
