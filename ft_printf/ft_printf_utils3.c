/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 23:10:19 by pauvicto          #+#    #+#             */
/*   Updated: 2022/10/10 01:26:12 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int	ft_process_str(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_wstring("(null)");
		return (6);
	}
	while (str[i])
	{
		ft_wchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_process_nbr(int nbr)
{
	int		nb_len;
	char	*number;

	nb_len = 0;
	number = ft_itoa(nbr); //Transforma o numero em string
	nb_len = ft_process_str(number); //Escreve a string
	free (number);
	return (nb_len);
}

int	ft_process_ptr(unsigned long long ptr) //ptr = endereço hexadecimal
{
	int	ptr_len;

	ptr_len = 0;
	if (ptr == 0)
		ptr_len = write(1, "(nil)", 5);
	else
	{
		ptr_len = write(1, "0x", 2); //indica que é codigo hexadecimal
		ft_wptr(ptr); //escreve o codigo do ponteiro
		ptr_len += ft_nbr_len_base(ptr, 16); //calcula o tamanho do ponteiro
	}
	return (ptr_len); //retorna o len do ptr
}

int	ft_process_unsigned(unsigned int nbr)
{
	int		nbr_len;
	char	*num;

	nbr_len = 0;
	if (nbr == 0)
		nbr_len = write(1, "0", 1);
	else
	{
		num = ft_unsigned_itoa(nbr); //passa os int pra ascii
		nbr_len += ft_process_str(num); //escreve os ascii
		free (num); //libera o malloc
	}
	
	return (nbr_len); //retorna o len do numero
}

int	ft_process_hex(unsigned int nbr, const char flag)
{
	int	nbr_len;

	if (nbr == 0) //verifica o 0
		return (write(1, "0", 1));
	else
		ft_whex(nbr, flag); //escreve o numero em sua forma hexadecimal
	nbr_len = ft_nbr_len_base(nbr, 16); //calcula o len do numero
	return (nbr_len); //retorna o len
}
