/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monabid <monabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:17:50 by monabid           #+#    #+#             */
/*   Updated: 2023/03/21 19:06:45 by monabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
void	get_attr(char *line, t_vars *vars)
{
	if (ft_strlen(line) < 2)
		invalid_line_err(line);
	if (line[0] == 'F' && ft_isspace(line[1]) == 1)
	if (line[0] == 'C' && ft_isspace(line[1]) == 1)
	if (line[0] == 'N' && line[1] == 'O' && ft_isspace(line[2]) == 1)
	if (line[0] == 'S' && line[1] == 'O' && ft_isspace(line[2]) == 1)
	if (line[0] == 'W' && line[1] == 'E' && ft_isspace(line[2]) == 1)
	if (line[0] == 'E' && line[1] == 'A' && ft_isspace(line[2]) == 1)
}
*/

void	paricing_test(t_vars *vars)
{
	printf("img N = %p | h = %i, w = %i\n"
		, vars->imgs.imgn.img,  vars->imgs.imgn.h,  vars->imgs.imgn.w);
	printf("img E = %p | h = %i, w = %i\n"
		, vars->imgs.imge.img,  vars->imgs.imge.h,  vars->imgs.imge.w);
	printf("img W = %p | h = %i, w = %i\n"
		, vars->imgs.imgw.img,  vars->imgs.imgw.h,  vars->imgs.imgn.w);
	printf("img S = %p | h = %i, w = %i\n"
		, vars->imgs.imgs.img,  vars->imgs.imgs.h,  vars->imgs.imgs.w);
	printf("floor color value = %i\n",vars->imgs.color_floor);
	printf("celing color value = %i\n",vars->imgs.color_celing);

	int	i;
	int	j;
	printf("maps :\n");
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			printf("%c", vars->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

}

int	main(int argc, char const *argv[])
{
	t_vars	vars;

	if (argc != 2)
		args_err();
	vars.p.a = 0;
	vars.mlx = mlx_init();
	validation(&vars, (char **)argv);
	paricing_test(&vars);
	return (0);
}

