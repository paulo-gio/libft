/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiovann <pgiovann@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 03:02:07 by pgiovann          #+#    #+#             */
/*   Updated: 2023/11/07 14:11:45 by pgiovann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Concatenates strings s1 and s2 into a new string

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sjoin;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len + 1;
	sjoin = malloc(total_len);
	if (!sjoin)
		return (NULL);
	sjoin[0] = '\0';
	ft_strlcat(sjoin, s1, s1_len + 1);
	ft_strlcat(sjoin, s2, total_len);
	return (sjoin);
}
