/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:33:28 by pauvicto          #+#    #+#             */
/*   Updated: 2022/06/24 19:03:28 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

/**
 * @brief The strchr() function returns a pointer to the first occurrence
       of the character c in the string s.
 * 
 * @param s const char
 * @param c int
 * @return char* 
 */
char	*ft_strchr(char *s, int c);

/**
 * @brief Allocates (with malloc(3)) and returns a newstring, which
 *  is the result of the concatenationof ’s1’ and ’s2’.
 * 
 * @param s1 char const *
 * @param s2 char const *
 * @return char* 
 */
char	*ft_strjoin(char *s1, char *s2);

/**
 * @brief The strlen() function calculates the length of the string pointed
       to by s, excluding the terminating null byte ('\0').
 * 
 * @param s const char *
 * @return size_t 
 */
size_t	ft_strlen(const char *s);

char	*get_next_line(int fd);

char	*clear_temp_line(char *temp_line);

char	*store_line(char *temp_line);

char	*reach_save_line(int fd, char *temp_line);
#endif