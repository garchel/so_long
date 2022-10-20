/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:35:14 by pauvicto          #+#    #+#             */
/*   Updated: 2022/10/15 00:10:39 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_rectan(char **map, int y) //Le o mapa e confere em todas as linhas se a quantidade de colunas é a mesma
{
	int	x1;
	int	x2;

	x1 = 0;
	x2 = 0;
	while (map[0][x1] && map[0][x1] != '\n') //trava a quantidade de linhas em 0 e percorre as colunas (y = 0, x ++)
		x1++;
	while (map[y][x2] && map[y][x2] != '\n') //passa a linha atual e conta a quantidade de colunas
		x2++;
	if (x2 == x1) //confere se a primeira e ultima linha tem a mesma quantidade de colunas
		return (1);
	return (0);
}

int	verif_closed(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (data->map[++y]) //percorre as linhas
	{
		x = -1;
		while (data->map[y][++x] && data->map[y][x] != '\n') //percorre as colunas - Aumenta o x (passando pra direita) até chegar no final da linha
		{
			if ((y == 0 || !data->map[y + 1]) && (data->map[y][x] != '1')) //se for a primeira ou ultima linha verifica se tá fechado // y = 0 primeira linha, data->map[y + 1] = ultima linha pq vai retornar falso pq n existe
			{
				write(1, "Error\nMap not closed by \"1\"\n", 28);
				return (0);
			}
			else if ((x == 0 || (data->map[y][x + 1] == '\n'
					|| !data->map[y][x + 1])) && (data->map[y][x] != '1')) //se for a primeira coluna ou a ultima verifica se tá fechado // x = 0 primeira coluna, data->map[y][x + 1] == \n é a ultima coluna
			{
				write(1, "Error\nMap not closed by \"1\"\n", 28);
				return (0);
			}
		}
	}
	return (1);
}

int	verif_map_components(t_data *data)
{
	if (data->c_count == 0) //verifica se há ao menos 1 moeda no mapa
	{
		write(1, "Error\nCollectible not found\n", 28);
		return (0);
	}
	if (data->p_count == 0) //verifica se há ao menos 1 player no mapa
	{
		write(1, "Error\nStarting point not found\n", 31);
		return (0);
	}
	if (data->p_count > 1) //verifica se há mais de 1 player no mapa
	{
		write(1, "Error\nMore than one starting point\n", 35);
		return (0);
	}
	if (data->e_count == 0) //verifica se há ao menos 1 saída no mapa
	{
		write(1, "Error\nExit not found\n", 21);
		return (0);
	}
	if (data->e_count > 1) //verifica se há ao menos 1 saída no mapa
	{
		write(1, "Error\nMore than one Exit\n", 25);
		return (0);
	}
	return (1);
}

int	element_count_inc(t_data *data, char c)
{
	if (c == '0' || c == '1') //se for parede ou chão retorna 1
		return (1);
	else if (c == 'C') //se for moeda retorna 1
	{
		data->c_count++; //aumenta o contador de moeda
		return (1);
	}
	else if (c == 'E') //se for saída retorna 1
	{
		data->e_count++; //aumenta o contador de saída
		return (1);
	}
	else if (c == 'P') //se for player retorna 1
	{
		data->p_count++; //aumenta o contador de player
		return (1);
	}
	ft_printf("\nError\nMap contain something else than \"0\",\"1\",\"C\",\"E\",\"P\"\n");
	return (0);
}

int	check_map(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map[++y]) //percorre linha
	{
		x = -1;
		while (data->map[y][++x] && data->map[y][x] != '\n') //percorre coluna
		{
			if (!element_count_inc(data, data->map[y][x])) //verifica se os elementos do mapa são somente os permitidos, caso contrário retorna falso(0)
				return (0);
		}
		if (!verif_rectan(data->map, y)) //verifica se o mapa é um retangulo, caso contrário retorna falso(0)
		{
			write(1, "Error\nMap is not a RECTANGLE\n", 29);
			return (0);
		}
	}
	data->check_c_count = data->c_count;
	if (!verif_map_components(data)) //verifica se há o número correto de elementos no mapa
		return (0);
	if (!verif_closed(data)) //verifica se o mapa é fechado com paredes
		return (0);
	return (1);
}