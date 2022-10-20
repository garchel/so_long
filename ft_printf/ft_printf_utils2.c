/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 23:10:19 by pauvicto          #+#    #+#             */
/*   Updated: 2022/10/10 01:21:17 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_nbr_len_base(uintptr_t nbr, int base) //usigned int pointer exatamente do tamanho do ponteiro
{
	int	nbr_len;

	nbr_len = 0;
	while (nbr != 0)
	{
		nbr_len++;
		nbr = nbr / base; // Passa as casas numericas da direita pra esquerda
	}
	return (nbr_len); //retorna o Len do numero
}

char	*ft_unsigned_itoa(unsigned int nbr)
{
	char	*num;
	int		nbr_len;

	nbr_len = ft_nbr_len_base(nbr, 10); //calcula o len do nbr
	num = (char *)malloc(sizeof(char) * (nbr_len + 1));
	if (!num) //verifica erro
		return (0);
	num[nbr_len] = '\0'; //coloca o '\0' no final
	while (nbr != 0)
	{
		num[nbr_len - 1] = nbr % 10 + '0'; //passa para o ponteiro de char 'num' o valor do resto de 'nbr' por 10 somado de '0' pra mudar pra ascii 
		nbr = nbr / 10; //atualiza o valor de nbr
		nbr_len--; //diminui o len pra mudar a posição
	}
	return (num); //retorna o ponteiro de char num
}
