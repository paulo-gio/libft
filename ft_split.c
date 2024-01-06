/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiovann <pgiovann@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 03:01:52 by pgiovann          #+#    #+#             */
/*   Updated: 2023/11/07 14:11:12 by pgiovann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Splits a string s into an array of strings, using c as a delimiter

static int	ft_word_count(const char *str, char delim)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != delim)
		{
			count++;
			while (*str && *str != delim)
				str++;
		}
		else
			str++;
	}
	return (count);
}

static void	ft_allocate_words(char **array, const char *str, char delim)
{
	int			i;
	const char	*start;

	i = 0;
	while (*str)
	{
		if (*str == delim)
			str++;
		else
		{
			start = str;
			while (*str && *str != delim)
				str++;
			array[i] = malloc((str - start + 1) * sizeof(char));
			if (!array[i])
			{
				while (i > 0)
					free(array[--i]);
				return ;
			}
			ft_strlcpy(array[i++], start, str - start + 1);
		}
	}
	array[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**result;

	if (!s)
		return (NULL);
	count = ft_word_count(s, c);
	result = malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	ft_allocate_words(result, s, c);
	if (!result[count])
		result[count] = NULL;
	else
	{
		free(result);
		return (NULL);
	}
	return (result);
}
