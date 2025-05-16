/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 10:40:54 by jvarila           #+#    #+#             */
/*   Updated: 2025/03/23 12:06:19 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *src, size_t size_old, size_t size_new)
{
	char	*dest;
	size_t	copy_bytes;

	if (!src)
		return (malloc(size_new));
	if (size_new == 0)
	{
		free(src);
		return (NULL);
	}
	dest = malloc(size_new);
	if (!dest)
		return (NULL);
	if (size_new > size_old)
		copy_bytes = size_old;
	else
		copy_bytes = size_new;
	while (copy_bytes--)
		dest[copy_bytes] = ((char *)src)[copy_bytes];
	free(src);
	return (dest);
}
