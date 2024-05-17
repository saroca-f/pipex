/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:34:01 by saroca-f          #+#    #+#             */
/*   Updated: 2024/04/01 13:27:27 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_situation_b(t_data_b *data, char *str)
{
	ft_printf("%s\n", str);
	free_matrix(data->path);
	free_super_matrix(data->command);
	free_matrix(data->path_command);
	exit (EXIT_FAILURE);
}

void	ft_pipex(t_data_b *data, char **env, int i)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error_situation_b(data, "pipe error");
	pid = fork();
	if (pid == -1)
		error_situation_b(data, "fork error");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		if (execve(data->path_command[i], data->command[i], env))
			error_situation_b(data, "evecve error");
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	data_free(t_data_b data)
{
	free_matrix(data.path);
	free_super_matrix(data.command);
	free_matrix(data.path_command);
}

void	other_case(t_data_b *data, char **argv, char **env)
{
	int			i;
	pid_t		pid;

	i = 2;
	fd_constructor(data->ac, argv, data, false);
	dup2(data->fd_in, STDIN_FILENO);
	while (i < data->ac - 2)
	{
		ft_pipex(data, env, i - 2);
		i++;
	}
	dup2(data->fd_out, STDOUT_FILENO);
	pid = fork ();
	if (pid == 0)
	{
		if (execve(data->path_command[i - 2], data->command[i - 2], env))
			error_situation_b(data, "evecve error");
	}
	else
		waitpid(pid, NULL, 0);
}

int	main(int argc, char **argv, char **env)
{
	t_data_b	data;

	data_init(&data, argc);
	if (ft_strcmp(argv[1], "here_doc"))
	{
		if (argc < 6)
		{
			printf("Do not enough arguments");
			exit(EXIT_FAILURE);
		}
		argument_control_b(&data, argv, env, true);
		here_doc_case(&data, argv, env);
	}
	else
	{
		if (argc < 5)
		{
			printf("Do not enough arguments");
			exit(EXIT_FAILURE);
		}
		argument_control_b(&data, argv, env, false);
		other_case(&data, argv, env);
	}
	data_free(data);
	return (0);
}
