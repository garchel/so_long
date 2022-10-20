/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:19:47 by pauvicto          #+#    #+#             */
/*   Updated: 2022/10/20 23:56:55 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_window_and_display(t_data *data)
{
	if (data->win) //se houver janela
		mlx_destroy_window(data->mlx, data->win); //destroi a janela
	if (data->mlx) //se houver o mlx
		mlx_destroy_display(data->mlx); //destroi o display
	free(data->mlx);
}

void	destroy_all_images(t_data *data) //destroi todas as imagens que foram guardadas
{
	if (data->img_player)
		mlx_destroy_image(data->mlx, data->img_player);
	if (data->img_exit)
		mlx_destroy_image(data->mlx, data->img_exit);
	if (data->img_collectible)
		mlx_destroy_image(data->mlx, data->img_collectible);
	if (data->img_wall)
		mlx_destroy_image(data->mlx, data->img_wall);
	if (data->img_floor)
		mlx_destroy_image(data->mlx, data->img_floor);
}

void	free_map(t_data *data) //inverso da parse
{
	int	i;

	i = -1;
	while (data->map[++i]) //enquanto houver mapa libera o espaço alocado
		free(data->map[i]);
	free(data->map);
	
}void	free_check_map(t_data *data) 
{
	int	i;

	i = -1;
	while (data->check_map[++i]) //enquanto houver mapa libera o espaço alocado
		free(data->check_map[i]);
	free(data->check_map);
}

int	free_handler(t_data *data)
{
	destroy_all_images(data);
	destroy_window_and_display(data);
	free_map(data);
	free_check_map(data);
	return (0);
}