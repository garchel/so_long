/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 00:48:52 by pauvicto          #+#    #+#             */
/*   Updated: 2022/10/10 01:06:06 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long int	len_nb(int n)
{
	int			len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*fill_nb(char *nb, unsigned int n_holder, long int len)
{
	nb[len--] = '\0';
	while (n_holder > 0)
	{
		nb[len--] = 48 + (n_holder % 10);
		n_holder = n_holder / 10;
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	char				*nb;
	long int			len;
	unsigned int		n_holder;

	len = len_nb(n);
	nb = (char *)malloc(sizeof(char) * (len + 1));
	if (!nb)
		return (NULL);
	if (n == 0)
		nb[0] = '0';
	if (n < 0)
	{
		n_holder = n * -1;
		nb[0] = '-';
	}
	else
		n_holder = n;
	nb = fill_nb(nb, n_holder, len);
	return (nb);
}
