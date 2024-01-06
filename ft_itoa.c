/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiovann <pgiovann@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 03:00:53 by pgiovann          #+#    #+#             */
/*   Updated: 2023/11/07 14:07:14 by pgiovann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Converts an integer to a null-terminated string
// handling negative values and INT_MIN

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_fill_str(char *str, int n, int len)
{
	while (len > 0)
	{
		str[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	int		offset;
	char	*str;

	len = ft_intlen(n);
	offset = 0;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (n == INT_MIN)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
		offset = 2;
	}
	else if (n < 0)
	{
		str[0] = '-';
		n = -n;
		offset = 1;
	}
	ft_fill_str(str + offset, n, len - offset);
	str[len] = '\0';
	return (str);
}
