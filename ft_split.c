/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:56:16 by dwotsche          #+#    #+#             */
/*   Updated: 2025/06/23 13:24:23 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_counter(const char *s, char c)
{
	int	i;
	int	word_count;
	int	sep_not_found;

	i = 0;
	word_count = 0;
	sep_not_found = 0;
	while (s[i])
	{
		if (s[i] != c && sep_not_found == 0)
		{
			sep_not_found = 1;
			word_count++;
		}
		else if (s[i] == c)
		{
			sep_not_found = 0;
		}
		i++;
	}
	return (word_count);
}

void	ft_fill(char const *s, char c, char **ret_strs, int wc)
{
	int	i;
	int	l;
	int	k;
	int	start;
	int	end;

	i = 0;
	k = 0;
	while (k < wc)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		ret_strs[k] = (char *)malloc(sizeof(char) * (end - start + 1));
		if (!ret_strs[k])
			return ;
		l = 0;
		while (start < end)
			ret_strs[k][l++] = s[start++];
		ret_strs[k++][l] = '\0';
	}
	ret_strs[k] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**ret_strs;

	word_count = ft_word_counter(s, c);
	ret_strs = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!ret_strs)
		return (NULL);
	ft_fill(s, c, ret_strs, word_count);
	return (ret_strs);
}
