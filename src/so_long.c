/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:40:09 by pauvicto          #+#    #+#             */
/*   Updated: 2022/10/21 00:21:19 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_init(t_data *data)
{
	data->win = mlx_new_window
		(data->mlx, (32 * data->w_win), (32 * data->h_win), "Game Window"); //tamanho do tile multiplicado pela largura e altura
	if (!data->win)
	{
		ft_printf("Error\nWindow initialisation failed\n");
		return (0);
	}
	return (1);
}

void	struct_init(t_data *data)
{
	data->c_count = 0;
	data->check_c_count = 0;
	data->p_count = 0;
	data->e_count = 0;
	data->s_count = 0;
	data->win = NULL;
	data->img_wall = NULL;
	data->img_player = NULL;
	data->img_exit = NULL;
	data->img_floor = NULL;
	data->img_collectible = NULL;
	data->target_x = 0;
	data->target_y = 0;
	data->img_width = SPRITE_WIDTH;
	data->img_height = SPRITE_HEIGHT;
}

int	check_map_extension(char *path) //Check if the map is .ber
{
	int	i;

	i = 0;
	while (path[i +4])
		i++;
	if (i - 1 >= 0 && path[i -1] != '/')
		if (i >= 1 && path[i] == '.' && path[i +1] == 'b'
			&& path[i +2] == 'e' && path[i +3] == 'r')
			return (1);
	return (0);
}

void	find_map_size(t_data *data) //calcula a altura e largura do mapa
{
	data->h_win = 0; //altura da janela
	data->w_win = 0; //largura da janela
	while (data->map[0][data->w_win] != '\n')
		data->w_win++;
	while (data->map[data->h_win])
		data->h_win++;
}

int main(int argc, char **argv)
{
	static t_data	data;

	if (argc == 2 && check_map_extension(argv[1])) //analisa se o mapa é .ber
	{
		data.mlx = mlx_init(); 						//inicializa o mlx
		if (!data.mlx)
			return (ft_printf("Error\nMlx initialisation failed\n"));
		struct_init(&data);							//inicializa a struct
		if (!gen_space(&data, argv[1])) 			//gera o mapa
			return (free_handler(&data));
		if (!gen_space2(&data, argv[1]))			//gera o mapa que vai ser usado pra verificação de caminho
			return (free_handler(&data));
		if (!check_map(&data))						//verifica se o mapa está dentro dos padrões		
			return (free_handler(&data));
		find_map_size(&data);						//calcula a altura e largura do mapa
		if (!win_init(&data))						//Inicia a janela
			return (free_handler(&data));
		if (!image_handler(&data))					//armazena as imagens
			return (free_handler(&data));
		if (!check_possible_path(&data))			//verifica se há um caminho possivel
			return (free_handler(&data));
		event_handler(&data);						//lida com o jogo
		return (free_handler(&data));
	}
	ft_printf("Error\nPlease provide .ber map\n");
}
