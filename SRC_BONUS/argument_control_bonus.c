/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_control_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:14:41 by saroca-f          #+#    #+#             */
/*   Updated: 2024/04/01 12:52:16 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	path_command_desing(t_data_b *data, int i)
{
	int		j;
	char	*ret;

	j = 0;
	ret = NULL;
	while (data->path[j])
	{
		ret = ft_command_join(data->path[j], data->command[i][0]);
		if (access(ret, F_OK | X_OK) == 0)
		{
			data->path_command[i] = ret;
			return ;
		}
		else
			free(ret);
		j++;
	}
	ft_printf ("command %s not found\n", data->command[i][0]);
	free_matrix(data->path);
	free_matrix(data->path_command);
	free_super_matrix(data->command);
	exit (0);
}

void	path_command_constructor(t_data_b *data)
{
	int		i;

	i = 0;
	while (data->command[i])
	{
		path_command_desing(data, i);
		i++;
	}
	data->path_command[i] = NULL;
}

char	***command_constructor(int argc, char **argv, bool here)
{
	int		i;
	int		j;
	char	***str;

	i = 1;
	j = 1;
	if (here == true)
	{
		i = 2;
		j = 2;
	}
	str = malloc(sizeof(char **) * (argc - (i + 1)));
	if (!str)
		return (NULL);
	while (i < argc - (j + 1))
	{
		str[i - j] = ft_split(argv[i + j], ' ');
		i++;
	}
	str[i - j] = NULL;
	return (str);
}

void	check_files(char **argv, t_data_b *data, bool here)
{
	if (access(argv[1], F_OK | R_OK) != 0 && here == false)
	{
		ft_printf("Error in infile permissions or not found\n");
		free_matrix(data->path);
		free_super_matrix(data->command);
		exit (5);
	}
}

void	argument_control_b(t_data_b	*dat, char **av, char **ev, bool h)
{
	int			i;
	int			j;
	char		*ret;

	dat->command = command_constructor(dat->ac, av, h);
	if (!dat->command)
		exit(EXIT_FAILURE);
	i = 0;
	j = 2;
	if (h == true)
		j = 3;
	while (ev[i] != NULL)
	{
		if (ft_strcmp(ev[i], "PATH="))
			break ;
		i++;
	}
	ret = ft_substr(ev[i], 5, ft_strlen(ev[i]));
	dat->path = ft_split(ret, ':');
	free (ret);
	check_files(av, dat, h);
	dat->path_command = malloc(sizeof(char *) * (dat->ac - j));
	path_command_constructor(dat);
}
