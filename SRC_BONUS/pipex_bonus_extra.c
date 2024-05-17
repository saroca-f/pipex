/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:01:58 by saroca-f          #+#    #+#             */
/*   Updated: 2024/04/01 13:29:52 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	fd_constructor(int argc, char **argv, t_data_b *dat, bool here_doc)
{
	if (here_doc == true)
	{
		dat->fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		if (dat->fd_out == -1)
			error_situation_b(dat, "open error");
	}
	else if (here_doc != true)
	{
		dat->fd_in = open(argv[1], O_RDONLY | O_CREAT, 0777);
		if (dat->fd_in == -1)
			error_situation_b(dat, "open error");
		dat->fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (dat->fd_out == -1)
			error_situation_b(dat, "open error");
	}
}

void	bucle_pipex(int argc, char **env, t_data_b *data)
{
	int		i;
	int		fd;
	pid_t	pid;

	i = 3;
	fd = open (".heredoc_tmp", O_RDONLY);
	dup2(fd, STDIN_FILENO);
	while (i < argc - 3)
	{
		ft_pipex(data, env, i - 3);
		i++;
	}
	close(fd);
	dup2(data->fd_out, STDOUT_FILENO);
	pid = fork();
	if (pid == -1)
		error_situation_b(data, "fork error");
	if (pid == 0)
	{
		if (execve(data->path_command[i - 3], data->command[i - 3], env))
			error_situation_b(data, "evecve error");
	}
	else
		waitpid(pid, NULL, 0);
}

void	bucle_gnl(char **argv, int fd)
{
	char	*ret;

	while (1)
	{
		ft_printf("heredoc> ");
		ret = get_next_line(STDIN_FILENO);
		if (!ft_strncmp(argv[2], ret, ft_strlen(argv[2]))
			&& ft_strlen(ret) - 1 == ft_strlen(argv[2]))
		{
			free(ret);
			return ;
		}
		ft_putstr_fd(ret, fd);
		free(ret);
	}
}

void	here_doc_case(t_data_b *data, char **argv, char **env)
{
	int		fd;

	fd_constructor(data->ac, argv, data, true);
	fd = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		error_situation_b(data, "open error");
		unlink(".heredoc_tmp");
		close (fd);
	}
	bucle_gnl(argv, fd);
	close (fd);
	bucle_pipex(data->ac, env, data);
	unlink(".heredoc_tmp");
}

void	data_init(t_data_b *data, int argc)
{
	data->ac = argc;
	data->command = NULL;
	data->path = NULL;
	data->path_command = NULL;
	data->fd_in = 0;
	data->fd_out = 0;
}
