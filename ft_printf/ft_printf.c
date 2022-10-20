/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:33:21 by pauvicto          #+#    #+#             */
/*   Updated: 2022/10/10 01:04:59 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_flag(va_list args, const char flag)
{
	int	print_msg;

	print_msg = 0;
	if (flag == 'c')
		print_msg = ft_wchar(va_arg(args, int));
	else if (flag == 'd' || flag == 'i')
		print_msg = ft_process_nbr(va_arg(args, int));
	else if (flag == 'p')
		print_msg = ft_process_ptr(va_arg(args, unsigned long long));
	else if (flag == 's')
		print_msg = ft_process_str(va_arg(args, char *));
	else if (flag == 'u')
		print_msg = ft_process_unsigned(va_arg(args, unsigned int));
	else if (flag == 'x' || flag == 'X')
		print_msg = ft_process_hex(va_arg(args, unsigned int), flag);
	else if (flag == '%')
		print_msg = ft_wpercent();
	return (print_msg); //retorna a msg a ser printada
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		char_pos;
	va_list	args; //cria a lista

	i = 0;
	char_pos = 0;
	va_start(args, str); //inicia a lista
	while (str[i]) //percorre a string
	{
		if (str[i] == '%') //se for flag
		{
			char_pos += ft_find_flag(args, str[i + 1]); //usa a função pra identificar a flag e retorna o que deve ser escrito
			i = i + 2;
		}
		else
		{
			char_pos += ft_wchar(str[i]); //escreve o caractere
			i++;
		}
	}
	va_end(args); //finaliza
	return (char_pos); //retorna a posição
}
