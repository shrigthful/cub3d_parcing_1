/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monabid <monabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:57:56 by monabid           #+#    #+#             */
/*   Updated: 2023/03/21 19:07:20 by monabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define WIN_W 1000
# define WIN_H 600
# define PI 3.14159265359

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "./libft/libft.h"


typedef struct s_cords
{
	int	x;
	int	y;
}	t_cords;

typedef struct s_img
{
	void	*img;
	int		h;
	int		w;
}	t_img;

typedef struct s_player
{
	t_cords	p;//plyer posission
	double	a;//view angle
}	t_player;

typedef struct s_assets
{
	t_img	imgn;
	t_img	imgs;
	t_img	imge;
	t_img	imgw;
	int		color_floor;
	int		color_celing;
}	t_assets;

typedef struct s_vars
{
	char		**map;
	t_player	p;
	t_assets	imgs;
	void		*mlx;
	void		*win;
}	t_vars;


//errors
void	malloc_err(void);
void	args_err(void);
void	file_err(void);
void	invalid_line_err(char *line, char *str);
void	error_exit(t_vars *vars, char *msg);
//utils
void	ft_free_split(char **split);
int		ft_isstr_digit(char *c);
int		get_win_heigth(char **map);
int		ft_isspace(char c);
void	end_game(t_vars *vars);
//hex
char	dig_to_hex(int i);
char	hex_to_dig(char i);
int		hex_to_int(char *hex_val);
//get_rgb
int		ft_atoi_rgb(char *str, char **split);
void	get_rgbval(char *line, void *to_set);
int		check_spit_content(char **split);
//get_imgpath
void	get_imgpath(char *line, void *to_set);
//gnl
char	*get_next_line(int fd);
//validaion
void	validation(t_vars *vars, char **argv);
//check_content
void	get_elements(t_vars *vars, int fd);
void	init_vars(t_vars *vars);
void	get_attr(char *line, t_vars *vars);
void	ft_remove_char(char *c, int index);
void	setup_val(char *line, void *to_set, int name);
void	check_content(t_vars *vars, char *path);
//ft_map
void	handle_map(t_vars *vars, int fd);

#endif
