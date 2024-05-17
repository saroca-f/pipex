/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:02:54 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/12 15:47:01 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	*ft_free(char **strs, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static int	cwords(char const *s, char c)
{
	int	times;
	int	rue;

	rue = 0;
	times = 0;
	while (*s)
	{
		if (*s != c && rue == 0)
		{
			times++;
			rue = 1;
		}
		else if (*s == c)
			rue = 0;
		s++;
	}
	return (times);
}

static char	**ft_while(char const *s, char c, char **st)
{
	int		wordcont;
	size_t	i;
	size_t	j;

	wordcont = -1;
	i = 0;
	j = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && wordcont < 0)
			wordcont = i;
		else if ((s[i] == c || i == ft_strlen(s)) && wordcont >= 0)
		{
			st[j] = ft_substr(s, wordcont, (i - wordcont));
			if (!st[j])
				return (ft_free(st, j));
			wordcont = -1;
			j++;
		}
		i++;
	}
	st[j] = NULL;
	return (st);
}

char	**ft_split(char const *s, char c)
{
	char	**st;

	st = malloc((cwords(s, c) + 1) * sizeof(char *));
	if (!st)
		return (NULL);
	st = ft_while(s, c, st);
	return (st);
}
