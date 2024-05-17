/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:46:42 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/21 17:15:48 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../pipex.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

char	*static_maker(char *static_str, int fd);
char	*make_line(char *static_str, int i);
char	*new_static_maker(char *static_str);
char	*get_next_line(int fd);

#endif