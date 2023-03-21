/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monabid <monabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:17:50 by monabid           #+#    #+#             */
/*   Updated: 2023/03/21 15:23:24 by monabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_file_name(char *path)
{
	char	*name;
	char	*start;

	start = ft_strrchr(path, '/');
	if (start == NULL)
		name = ft_strdup(path);
	else
		name = ft_strdup(start + 1);
	if (name == NULL)
		malloc_err();
	return (name);
}

void	check_name(char *name)
{
	int	i;

	if (name == NULL)
		args_err();
	if (*name == 0)
	{
		free(name);
		args_err();
	}
	i = ft_strlen(name) - 1;
	if (!(name[i] == 'b' && name[i - 1] == 'u'
		&& name[i - 2] == 'c' && name[i - 3] == '.'))
	{
		free(name);
		args_err();
	}
}

void	check_content(t_vars *vars, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		file_err();
	get_elements(vars, fd);
}


void	validation(t_vars *vars, char **argv)
{
	char *name;

	name = get_file_name(argv[1]);
	check_name(name);
	free(name);
	check_content(vars, argv[1]);
}
