/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 03:47:33 by pauvicto          #+#    #+#             */
/*   Updated: 2022/10/10 06:32:34 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	step_handler(t_data *data)
{
	ft_printf("\r%i", ++data->s_count); //escreve o numero de passos e aumenta o numero de passos
	if (data->tile == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img_exit,
			32 * data->h_x, 32 * data->h_y);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img_floor,
			32 * data->h_x, 32 * data->h_y);
}

int	move_player_up(t_data *data)
{	
	data->tile = data->map[data->h_y][data->h_x];
	step_handler(data);
	if (data->map[data->h_y - 1][data->h_x] == 'C') //se nessa posição houver uma moeda
	{
		data->c_count--; //diminui a contagem de moedas
		data->map[data->h_y - 1][data->h_x] = '0'; //a posição passa a não ter mais moeda
	}
	else if (data->map[data->h_y - 1][data->h_x] == 'E' && data->c_count == 0) //se nessa posição for a saída e a quantidade de moedas restantes for 0
		return (write(1, "\nWell Done! :D\n", 15));
	mlx_put_image_to_window(data->mlx, data->win, data->img_player,
		32 * data->h_x, 32 * --data->h_y); //se nao deu gg nem pegou a moeda, move o player pra posição
	return (0);
}

int	move_player_left(t_data *data)
{	
	data->tile = data->map[data->h_y][data->h_x];
	step_handler(data);
	if (data->map[data->h_y][data->h_x - 1] == 'C')
	{
		data->c_count--;
		data->map[data->h_y][data->h_x - 1] = '0';
	}
	else if (data->map[data->h_y][data->h_x - 1] == 'E' && data->c_count == 0)
		return (write(1, "\nWell Done! :D\n", 15));
	mlx_put_image_to_window(data->mlx, data->win, data->img_player,
		32 * --data->h_x, 32 * data->h_y);
	return (0);
}

int	move_player_down(t_data *data)
{	
	data->tile = data->map[data->h_y][data->h_x];
	step_handler(data);
	if (data->map[data->h_y + 1][data->h_x] == 'C')
	{
		data->c_count--;
		data->map[data->h_y + 1][data->h_x] = '0';
	}
	else if (data->map[data->h_y + 1][data->h_x] == 'E' && data->c_count == 0)
		return (write(1, "\nWell Done! :D\n", 15));
	mlx_put_image_to_window
		(data->mlx, data->win, data->img_player,
			32 * data->h_x, 32 * ++data->h_y);
	return (0);
}

int	move_player_right(t_data *data)
{	
	data->tile = data->map[data->h_y][data->h_x];
	step_handler(data);
	if (data->map[data->h_y][data->h_x + 1] == 'C')
	{
		data->c_count--;
		data->map[data->h_y][data->h_x + 1] = '0';
	}
	else if (data->map[data->h_y][data->h_x + 1] == 'E' && data->c_count == 0)
		return (write(1, "\nWell Done! :D\n", 15));
	mlx_put_image_to_window(data->mlx, data->win, data->img_player,
		32 * ++data->h_x, 32 * data->h_y);
	return (0);
}