/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:30:47 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/12 16:00:59 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	char	*s2;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	s1 = malloc(len + 1);
	if (!s1)
		return (NULL);
	s2 = s1;
	while (len--)
	{
		*s2 = s[start];
		s2++;
		start++;
	}
	*s2 = '\0';
	return (s1);
}
