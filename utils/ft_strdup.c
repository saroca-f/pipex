/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:01:44 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/12 16:04:45 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strdup(const char *s1)
{
	size_t		len;
	char		*s2;
	char		*s3;

	len = 0;
	while (s1[len])
		len++;
	s2 = malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	s3 = s2;
	while (*s1)
		*s3++ = *s1++;
	*s3 = '\0';
	return (s2);
}
