/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:17:30 by pauvicto          #+#    #+#             */
/*   Updated: 2022/10/10 04:41:42 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_data *data, char c) //função que executa a movimentação do player
{
	int	check;

	check = 0;
	if (c == 'W' && data->map[data->h_y - 1][data->h_x] != '1') //se for para subir e em cima não for parede
	{
		if (data->map[data->h_y -1][data->h_x] != 'E' || data->c_count == 0)
			check = move_player_up(data);
	}
	if (c == 'A' && data->map[data->h_y][data->h_x - 1] != '1') //se for para a esquerda e na esquerda nao houver parede
	{	
		if (data->map[data->h_y][data->h_x - 1] != 'E' || data->c_count == 0)
			check = move_player_left(data);
	}
	if (c == 'S' && data->map[data->h_y + 1][data->h_x] != '1') //se for para descer e embaixo não houver parede
	{
		if (data->map[data->h_y + 1][data->h_x] != 'E' || data->c_count == 0)
			check = move_player_down(data);
	}
	if (c == 'D' && data->map[data->h_y][data->h_x + 1] != '1') //se for para a direita e na direita não houver parede
	{
		if (data->map[data->h_y][data->h_x + 1] != 'E' || data->c_count == 0)
			check = move_player_right(data);
	}
	if (check)
		mlx_loop_end(data->mlx);
}

int	check_key_pressed(int key, t_data *data)
{
	if (key == 65307) //ESC
	{
		ft_printf("\n");
		mlx_loop_end(data->mlx);
	}
	else if (key == 119)
		move_player(data, 'W'); //subir = diminuir uma linha
	else if (key == 97)
		move_player(data, 'A'); //ir pra direita = aumentar uma coluna
	else if (key == 115)
		move_player(data, 'S'); //descer = aumentar uma linha
	else if (key == 100)
		move_player(data, 'D'); //ir pra esquerda = diminuir uma coluna
	return (0);
}

void	event_handler(t_data *data)
{
	//find_player_pos(data);
	mlx_key_hook(data->win, &check_key_pressed, data); //função q capta a key sendo pressionada e inicia a sequencia de movimento
	mlx_hook(data->win, 17, 0, mlx_loop_end, data->mlx); //possibilita fechar o programa clicando no X
	mlx_expose_hook(data->win,  &image_handler, data); //reescreve as imagens quando rola o expose
	mlx_loop(data->mlx);	
}