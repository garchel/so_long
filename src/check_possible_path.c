/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_possible_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:56:21 by pauvicto          #+#    #+#             */
/*   Updated: 2022/10/15 00:11:19 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	clear_path(t_data *data)
{
	int	x;
	int y;
	
	y = -1;
	while (data->check_map[++y])
	{
		x = -1;
		while (data->check_map[y][++x])
		{
			if (data->check_map[y][x] == '3')
				data->check_map[y][x] = '0';
		}
	}
}

void	find_target_pos(t_data *data, char target)
{
	int	x;
	int	y;

	y = -1;
	while (data->map[++y]) //percorre as linhas
	{
		x = -1;
		while (data->map[y][++x] && data->map[y][x] != '\n') //percorre as colunas
		{
			if (data->map[y][x] == 'P') //se na posição houver um player
			{
				data->h_y = y; //armazena a linha do player
				data->h_x = x; //armazena a coluna do player
			}
			if (data->check_map[y][x] == target) //se na posição for o alvo
			{
				data->target_y = y; //armazena a linha do alvo
				data->target_x = x;
			}
		}
	}
}

int	look_for_target(t_data *data, int t_x, int t_y, char target)
{
	ft_printf("\nCheckando Posição X: %d , Y: %d", t_x, t_y);
	ft_printf("\nChar da posição: %c", data->check_map[t_y][t_x]);
	//se nessa posição estiver o alvo, finaliza
	if (data->check_map[t_y][t_x] == target)
	{
		ft_printf("\nPath to %c found!\n", target);
		if (target == 'C')
		{
			data->check_map[t_y][t_x] = '0';
			data->check_c_count--;
		}
		return (1);
	}
	else
		if (data->check_map[t_y][t_x] != 'E')
			data->check_map[t_y][t_x] = '3';
	if (data->check_map[t_y][t_x - 1] != '1' && data->check_map[t_y][t_x - 1] != '3') //esquerda se nao houver parede
	{	
		//Envia a nova posição e chama dnv
		if (look_for_target(data, (t_x - 1), t_y, target))
			return (1);
	}
	if (data->check_map[t_y - 1][t_x] != '1' &&  data->check_map[t_y - 1][t_x] != '3') //subir se em cima não for parede
	{
		//Envia a nova posição e chama dnv
		if (look_for_target(data, t_x, (t_y - 1), target))
			return (1);
	}
	if (data->check_map[t_y][t_x + 1] != '1' && data->check_map[t_y][t_x + 1] != '3') //direita e se não houver parede
	{
		//Envia a nova posição e chama dnv
		if (look_for_target(data, (t_x + 1), t_y, target))
			return (1);
	}
	if (data->check_map[t_y + 1][t_x] != '1' && data->check_map[t_y + 1][t_x] != '3') //descer se em baixo não for parede
	{
		//Envia a nova posição e chama dnv
		if (look_for_target(data, t_x, (t_y + 1), target))
			return (1);
	}

	return (0);
}

int	check_possible_path(t_data *data)
{
	//armazena a pos inicial
	int	t_x;
	int	t_y;

	//ft_printf("Posição do player: y:%d x:%d\n", data->h_y, data->h_x);
	while (data->check_c_count != 0)
	{
		find_target_pos(data, 'C'); //acha a posição do colecionavel
		t_x = data->h_x;
		t_y = data->h_y;
		if (!look_for_target(data, t_x, t_y, 'C'))
		{
			ft_printf("\nError\nNo possible path found to reach all the collectibles!\n");
			return (0);
		}
		clear_path(data);
		ft_printf("Colecionáveis restantes: %d\n", data->check_c_count);
	}
	find_target_pos(data, 'E'); //acha a posição da saída
	if (!look_for_target(data, t_x, t_y, 'E'))
		{
			ft_printf("\nError\nNo way out found! Exit might be impossible to reach.\n");
			return (0);
		}
	return (1);
}