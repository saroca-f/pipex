/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:05:51 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/20 16:47:56 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	cont;

	cont = 0;
	while ((cont < n) && ((s1[cont] != '\0') || (s2[cont] != '\0')))
	{
		if (s1[cont] != (s2[cont]))
			return ((unsigned char)s1[cont] - ((unsigned char)s2[cont]));
		cont++;
	}
	return (0);
}
