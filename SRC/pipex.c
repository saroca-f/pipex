/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:39:26 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/20 12:50:55 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_situation(t_data data, char *str)
{
	ft_printf("%s\n", str);
	free_matrix(data.path);
	free_matrix(data.command1);
	free_matrix(data.command2);
	free(data.path_command1);
	free(data.path_command2);
	exit (EXIT_FAILURE);
}

void	children_process(char **argv, int *pipefd, char **env, t_data data)
{
	int	fd;

	close(pipefd[0]);
	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
	{
		ft_printf("Open error\n");
		exit(EXIT_FAILURE);
	}
	dup2(fd, 0);
	dup2(pipefd[1], 1);
	if (execve(data.path_command1, data.command1, env) == -1)
		exit(1);
}

void	children2_process(char **argv, int *pipefd, char **env, t_data data)
{
	int	fd;

	close(pipefd[1]);
	fd = open(argv[4], 1 | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
	{
		ft_printf("Open error\n");
		exit(EXIT_FAILURE);
	}
	dup2(fd, 1);
	dup2(pipefd[0], 0);
	if (execve(data.path_command2, data.command2, env) == -1)
		exit(1);
}

void	father_process(t_data data)
{
	free_matrix(data.path);
	free_matrix(data.command1);
	free_matrix(data.command2);
	free(data.path_command1);
	free(data.path_command2);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	pid_t	pid;
	pid_t	pid2;
	int		pipefd[2];

	data = argument_control(argc, argv, env);
	if (pipe(pipefd) == -1)
		error_situation(data, "Pipe error");
	pid = fork();
	if (pid == -1)
		error_situation(data, "Fork error");
	if (pid == 0)
		children_process(argv, pipefd, env, data);
	pid2 = fork();
	if (pid2 == -1)
		error_situation(data, "Fork error");
	if (pid2 == 0)
		children2_process(argv, pipefd, env, data);
	else
		father_process(data);
	return (0);
}
