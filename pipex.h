/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:40:45 by saroca-f          #+#    #+#             */
/*   Updated: 2024/04/01 13:22:50 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdbool.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_data
{
	char			**path;
	char			**command1;
	char			**command2;
	char			*path_command1;
	char			*path_command2;
}					t_data;

typedef struct s_data_b
{
	int				ac;
	char			**path;
	char			***command;
	char			**path_command;
	int				fd_in;
	int				fd_out;
}					t_data_b;

//process
void	data_init(t_data_b *data, int argc);
void	ft_pipex(t_data_b *data, char **env, int i);
void	here_doc_case(t_data_b *data, char **argv, char **env);
void	fd_constructor(int argc, char **argv, t_data_b *data, bool here_doc);

//error
void	error_situation_b(t_data_b *data, char *str);

//utils
void	free_matrix(char **str);
void	free_super_matrix(char ***str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
bool	ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	ft_putstr_fd(char *s, int fd);

//control
t_data	argument_control(int argc, char **argv, char **env);
void	argument_control_b(t_data_b	*dat, char **av, char **ev, bool h);
char	*ft_command_join(char const *s1, char const *s2);

#endif