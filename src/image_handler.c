/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:47:52 by pauvicto          #+#    #+#             */
/*   Updated: 2022/10/10 04:56:42 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	*select_img(char a, t_data *data) //verifica baseado no char enviado, qual img será selecionada
{
	if (a == 'P')
		return (data->img_player);
	if (a == 'E')
		return (data->img_exit);
	if (a == 'C')
		return (data->img_collectible);
	if (a == '1')
		return (data->img_wall);
	if (a == '0')
		return (data->img_floor);
	return (0);
}

int	put_img(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (data->map[++x]) //percorre as linhas
	{
		y = -1;
		while (data->map[x][++y] && data->map[x][y] != '\n') //percorre as colunas
			mlx_put_image_to_window(data->mlx, data->win, select_img
				(data->map[x][y], data), 32 * y, 32 * x); //coloca a imagem
	}
	return (1);
}

int	store_assets(t_data *data)
{
	data->img_player = mlx_xpm_file_to_image
		(data->mlx, "img/player_so_long.xpm", &data->img_width, &data->img_height); //define o asset pro player
	if (!data->img_player)
		return (0);
	data->img_exit = mlx_xpm_file_to_image
		(data->mlx, "img/exit_so_long.xpm", &data->img_width, &data->img_height); //define o asset pra saída
	if (!data->img_exit)
		return (0);
	data->img_collectible = mlx_xpm_file_to_image
		(data->mlx, "img/bau_so_long.xpm", &data->img_width, &data->img_height); //define o asset pro colecionavel
	if (!data->img_collectible)
		return (0);
	data->img_wall = mlx_xpm_file_to_image
		(data->mlx, "img/wall_so_long.xpm", &data->img_width, &data->img_height); //define o asset pra parede
	if (!data->img_wall)
		return (0);
	data->img_floor = mlx_xpm_file_to_image
		(data->mlx, "img/tile_so_long.xpm", &data->img_width, &data->img_height); //define o asset pro chão
	if (!data->img_floor)
		return (0);
	return (1);
}

int	image_handler(t_data *data)
{
	if (!store_assets(data)) //registra os assets nas variáveis
	{
		ft_printf("Error\nInvalid image, initialisation failed\n");
		return (0);
	}
	if (data->win != NULL)
		put_img(data); //coloca as imagens
	return (1);
}