/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_super_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:35:34 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/18 11:43:22 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_super_matrix(char ***str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free_matrix(str[i]);
		i++;
	}
	free(str);
}