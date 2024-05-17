/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:36:14 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/21 18:07:34 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_command(t_data data, char *command, char **path)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	while (data.path[i])
	{
		ret = ft_command_join(data.path[i], command);
		if (access(ret, F_OK | X_OK) == 0)
		{
			*path = ret;
			return ;
		}
		free(ret);
		i++;
	}
	ft_printf ("command %s do not found\n", command);
	free_matrix(data.path);
	free_matrix(data.command1);
	free_matrix(data.command2);
	if (data.path_command1)
		free(data.path_command1);
	exit (0);
}

void	check_files(char **argv, t_data data)
{
	if (access(argv[1], F_OK | R_OK) != 0)
	{
		ft_printf("Error in infile permissions or not found\n");
		free_matrix(data.path);
		free_matrix(data.command1);
		free_matrix(data.command2);
		exit (5);
	}
}

t_data	argument_control(int argc, char **argv, char **env)
{
	int		i;
	char	*ret;
	t_data	data;

	if (argc != 5)
	{
		ft_printf("Number of parameters is wrong\n");
		exit (1);
	}
	data.command1 = ft_split(argv[2], ' ');
	data.command2 = ft_split(argv[3], ' ');
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strcmp(env[i], "PATH="))
			break ;
		i++;
	}
	ret = ft_substr(env[i], 5, ft_strlen(env[i]));
	data.path = ft_split(ret, ':');
	free (ret);
	check_files(argv, data);
	check_command(data, data.command1[0], &data.path_command1);
	check_command(data, data.command2[0], &data.path_command2);
	return (data);
}
