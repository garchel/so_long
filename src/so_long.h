/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 01:01:40 by pauvicto          #+#    #+#             */
/*   Updated: 2022/10/14 20:59:41 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# define SPRITE_WIDTH 32
# define SPRITE_HEIGHT 32

# include "../mlx_linux/mlx.h"
# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"

typedef struct s_data
{
	void	*mlx; //mlx
	void	*win; //janela
	void	*img_wall; //xpm da parede
	void	*img_player; //xpm do player
	void	*img_exit; //xpm da saída
	void	*img_floor; //xpm do chão
	void	*img_collectible; //xpm do colecionavel
	int		c_count; //numero de colecionaveis
	int		check_c_count;
	int		p_count; //numero de players
	int		e_count; //numero de saídas
	int		s_count; //step count
	int		h_win; //altura da janela
	int		w_win; //largura da janela
	int		h_y; //linha do mapa
	int		h_x; //coluna do mapa
	int		target_y;
	int		target_x;
	char	**map; //mapa
	char	**check_map; //mapa pra verificação
	char	tile;
	int		img_width;
	int		img_height;
}	t_data;

int		check_map(t_data *data);
int		free_handler(t_data *data);
int		image_handler(t_data *data);
void	event_handler(t_data *data);
int		move_player_right(t_data *data);
int		move_player_left(t_data *data);
int		move_player_up(t_data *data);
int		move_player_down(t_data *data);
int		gen_space(t_data *data, char *path);
int		gen_space2(t_data *data, char *path);
int		check_possible_path(t_data *data);

#endif