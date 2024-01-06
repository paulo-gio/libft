/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiovann <pgiovann@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 03:02:31 by pgiovann          #+#    #+#             */
/*   Updated: 2023/11/07 14:14:34 by pgiovann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates and returns a new string containing s1 minus the characters
// found in set, in the beginning and the end.

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*trim;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = (char *)s1;
	while (*start && ft_strchr(set, *start))
		start++;
	end = (char *)(s1 + ft_strlen(s1) - 1);
	while (end >= start && ft_strchr(set, *end))
		end--;
	len = end - start + 1;
	trim = malloc(len + 1);
	if (!trim)
		return (NULL);
	ft_memcpy(trim, start, len);
	trim[len] = '\0';
	return (trim);
}
