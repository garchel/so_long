/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 23:10:19 by pauvicto          #+#    #+#             */
/*   Updated: 2022/10/10 01:29:03 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_wchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_wstring(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_wchar(str[i]);
		i++;
	}
}

void	ft_wptr(uintptr_t nbr)  //usigned int pointer exatamente do tamanho do ponteiro
{
	if (nbr >= 16)
	{
		ft_wptr(nbr / 16); //Aprofunda no numero, mirando no menor grupo 16
		ft_wptr(nbr % 16); //Volta as casas, mira nos proximos grupos 16
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd((nbr + '0'), 1); //Escreve o numero somando o 0 pra converter pra ascii
		else
			ft_putchar_fd((nbr - 10 + 'a'), 1); //Escreve a letra que o numero corresponderia, somando 'a' pra mudar pra ascii e tirando 10 pra achar a posição da letra
	}	
}

void	ft_whex(unsigned int nbr, const char flag)
{
	if (nbr >= 16)
	{
		ft_whex(nbr / 16, flag); //Aprofunda no numero
		ft_whex(nbr % 16, flag); // Volta as casas
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd((nbr + '0'), 1); //Escreve o numero somando 0 pra mudar pra ascii
		else
		{
			if (flag == 'x')
				ft_putchar_fd((nbr - 10 + 'a'), 1); // Escreve a letra correspondente
			if (flag == 'X')
				ft_putchar_fd((nbr - 10 + 'A'), 1);
		}
	}
}

int	ft_wpercent(void)
{
	write(1, "%", 1);
	return (1);
}
