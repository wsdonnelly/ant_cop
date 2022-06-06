/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:16:58 by wdonnell          #+#    #+#             */
/*   Updated: 2022/06/06 12:06:51 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_str_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free (arr[i++]);
	free (arr);
}

static int	ft_word_count(const char *str, char d)
{
	int		flag;
	int		i;
	int		wc;

	i = 0;
	wc = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == d)
		{
			flag = 0;
			i++;
		}
		while (str[i] != '\0' && str[i] != d)
		{
			flag = 1;
			i++;
		}
		if (flag == 1)
			wc++;
	}
	return (wc);
}
static char	*ft_dstrtrim(char **p, char d)
{
	char				*new;
	char				*temp;
	unsigned int		start;
	unsigned int		end;
	unsigned int		i;

	start = 0;
	while (((*p)[start] == d && (*p)[start] != '\0'))
		start++;
	end = start;
	while ((*p)[end] != d && (*p)[end] != '\0')
		end++;
	new = (char *)malloc(sizeof(char) * (end - start + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < (end - start))
	{
		new[i] = (*p)[i + start];
		i++;
	}
	new[i] = '\0';
	temp = &((*p)[end]);
	*p = temp;
	return (new);
}

char	**ft_strsplit(char const *s, char c)
{
	char				**str_arr;
	char				*p;
	unsigned int		wc;
	unsigned int		i;

	if (!s)
		return (NULL);
	p = (char *)s;
	wc = ft_word_count(s, c);
	str_arr = (char **)malloc(sizeof(char *) * (wc + 1));
	if (str_arr == NULL)
		return (NULL);
	i = 0;
	while (i < wc)
	{
		str_arr[i] = ft_dstrtrim(&p, c);
		i++;
	}
	str_arr[i] = NULL;
	return (str_arr);
}
