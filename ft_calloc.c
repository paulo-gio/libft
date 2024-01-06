/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiovann <pgiovann@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:52:23 by pgiovann          #+#    #+#             */
/*   Updated: 2023/11/07 14:05:47 by pgiovann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocate and zero-initialize array memory

void	*ft_calloc(size_t elements, size_t size)
{
	size_t			total_size;
	unsigned char	*ptr;

	total_size = elements * size;
	if (elements != 0 && size != 0 && total_size / elements != size)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}
