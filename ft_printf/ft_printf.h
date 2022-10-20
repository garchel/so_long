/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:53:37 by pauvicto          #+#    #+#             */
/*   Updated: 2022/10/10 01:12:02 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<stdarg.h>
# include	<unistd.h>
# include	<stdint.h>
# include	<stdlib.h>

char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);

int		ft_printf(const char *str, ...);
int		ft_find_flag(va_list args, const char flag);

int		ft_wchar(int c);
void	ft_wstring(char *str);
void	ft_wptr(uintptr_t nbr);
void	ft_whex(unsigned int nbr, const char flag);
int		ft_wpercent(void);

char	*ft_unsigned_itoa(unsigned int nbr);
int		ft_nbr_len_base(uintptr_t nbr, int base);
int		ft_num_len(unsigned	int num);

int		ft_process_str(const char *str);
int		ft_process_nbr(int nbr);
int		ft_process_ptr(unsigned long long ptr);
int		ft_process_unsigned(unsigned int nbr);
int		ft_process_hex(unsigned int nbr, const char flag);

#endif
